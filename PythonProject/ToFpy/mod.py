# Testing by Michelle P 9/4/23 - MODULE FILE
""" Keep Multiprocessing 
    1. add: typesetting
    2. Move run() out of Simulation Class   
    3. add: Pool.close() and Pool.join() in that order
    4. Compile module program 
"""

# Installs Needed 
import numpy as np #analysis
import pandas as pd #analysis
from tqdm import tqdm #progressbar
# Native 
import random #generator 
from time import perf_counter, perf_counter_ns #timing 
from datetime import timedelta, datetime #timing
from memory_profiler import profile #memory checks

# Testing Multiprocessing 
from multiprocessing import Pool, cpu_count, freeze_support
from concurrent.futures import ProcessPoolExecutor

# Typesetting 
from typing import Union, List
from numpy.typing import ArrayLike

class Simulation:
    
    def __init__(self):
        #############################
        # CONSTANTS
        #############################
        self.c = 0.0299792/1.58 # Speed of Light in cm / ps
        self.q = 1.60217663e-19 # charge of electron columbs
        # CONSTRAINT n_1 <= n_2
        # SIMULATOR FIELDS
        self.n_1 = 1.000293 # Sample index of refraction of air
        self.n_2 = 1.58 # 1.58 for EJ-200
        self.T3z=0 #cm is the bottom of T3
        self.T1z=33.782 #cm is the bottom of T1
        self.T4z=-28.07297 #cm is the bottom of T4
        self.T1_radius = 13 #cm
        self.T4_radius = 18 #cm
        self.T1_width = 0.5 #cm
        self.T4_width = 1 #cm
        self.T1top = self.T1z+self.T1_width
        self.T4top = self.T4z+self.T4_width
        self.T1_corner_radius = self.T1_width*4
        self.T4_corner_radius = self.T4_width*4
        self.T1_corner_center = [self.T1_radius-self.T1_corner_radius,self.T1_corner_radius-self.T1_radius, self.T1_radius]
        self.T4_corner_center = [self.T4_corner_radius-self.T4_radius, self.T4_radius-self.T4_corner_radius, self.T4_radius]
        self.PMT1_center = [self.T1_radius-4*0.5,-self.T1_radius+4*0.5,self.T1z]
        self.PMT4_center = [-self.T4_radius+4*0.5,self.T4_radius-4*0.5,self.T4z]
        self.xPMT4=9.5*np.cos(np.radians(110))*2.54
        self.yPMT4=9.5*np.sin(np.radians(110))*2.54
        self.xPMT1=8.*np.cos(np.radians(-45))*2.54 # x2PMT1=8.*np.cos(np.radians(-53.72))*2.54 For test
        self.yPMT1=8.*np.sin(np.radians(-45))*2.54 # y2PMT1=8.*np.sin(np.radians(-53.72))*2.54 For test
        self.PMT1_radius = 4.6/2 #cm need to change this to 46 milimeters or 0.046 cm
        self.PMT4_radius = 4.6/2 #cm 
        # PMT SIGNAL GENERATION FIELDS 
        self.n_dynodes = 8
        self.V = np.linspace(150,850,self.n_dynodes)
        # self.V = [150,300,350,600,750,850]
        self.E_per_electron = 20
        self.QE = 1 #0.23
        self.sigma_smoothing = 400 #ps
        self.t_initial = 0 #ps
        self.particle_init_angle_range = 40 #degrees
        self.particle_gen_area = self.T1_radius
        self.particle_gen_z = self.T1z+self.T1_width + 2 #cm
        self.mean_free_path_scints = 24e-5 #cm or 80 micro meters
        self.photons_produced_per_MeV = 10 # true value is closer to 10000 per 1MeV
        self.pr_of_scintillation = 0.8
        self.max_simulated_reflections = 40
        self.pmt_electron_travel_time = 0 # approx 16 ns
        self.artificial_gain = 1 # gain factor
        self.pr_absorption = 0.1 # probability of boundary absorbing
        self.seperation_time = 1e5 # ps 
        self.output_bin_width = 100 # ps
        self.num_particles = 1 # default Muons
        self.CMOS_thresh = 1.5 # V for rising edge detector
        self.reemission_angle_factor = 0.9 # range [0,1] --> cone from [-pi,pi]
        
        # Introduction Print Statement
        print("######################################################")
        print("Generated Apparatus Simulation with following defaults")
        print("######################################################")
        print("PARTICLE: Mean Free Path =", self.mean_free_path_scints, "cm")
        print("PARTICLE: Time Seperation between sequential Particles if simulation more than 1 =",self.seperation_time)
        print("SCINT:    Probability of Scintillaton =", self.pr_of_scintillation)
        print("PMT:      Quantum Efficiency is set to", self.QE, "by default to keep more pulses")
        print("PMT:      Energy per Photoelectron is set to", self.E_per_electron, "by best estimation")
        print("PMT:      Artificial Gain on Output Current =", self.artificial_gain)
        print("OUTPUT:   Binning Width for PWL output file =", self.output_bin_width, "ps")
        print("\nRun with .run() function given optional arguments below")
        print("integer n particles, 'delta_t' =", self.seperation_time, "ps particle time seperation")
        
    #############################
    # HELPER FUNCTIONS
    #############################

    # FIND SIGNIFICANT DIGIT POWER OF 10
    def round_to_sig(self, x):
        return -int(np.floor(np.log10(np.abs(x))))

    # NORMALIZE A VECTOR
    def normalize(self, x):
        x /= np.linalg.norm(x)
        return x
    
    # LIGHT GUIDE CONDITION
    def lg_condition(self, corner_pt, scint_corner, scint_num):
        ret = (corner_pt[0] > 0) & (corner_pt[0] < scint_corner[0]) & (corner_pt[1] < 0) & (corner_pt[1] > scint_corner[1])
        if scint_num == 4:
            ret = (corner_pt[0] > 0) & (corner_pt[0] < scint_corner[0]) & (corner_pt[1] < 0) & (corner_pt[1] > scint_corner[1])
        return ret

    # SCINT RADIUS CONDITION
    def scint_condition(self, corner_pt, scint_radius, scint_num):
        ret = np.sqrt(np.sum(corner_pt[0:2]**2)) < self.T1_radius
        if scint_num == 4:
            ret = np.sqrt(np.sum(corner_pt[0:2]**2)) < self.T4_radius
        return ret

    # DISTANCE 2-DIM CIRCLE WITH LINE SEGMENT
    # t = -D . ∆ ± √(D . ∆)^2 - |D|^2(|∆|^2 - R^2)
    #     over |D|^2
    # ARGUMENTS : # 3d directional vector, 3d point, center of scintillator, radius of scintillator, use corner circle boolean
    def distance_circle(self, u, o, center, radius, quadrant=False): 
        cond = np.dot(u,o) < 0
        D = u*-1 if cond else u # does a normalized vector in 3d equate to normalized vector in 2d?
        bigDelta = np.array(o)-np.array(center)
        magDsq = np.linalg.norm(D)**2
        magDeltasq = np.linalg.norm(bigDelta)**2
        DdotDelta = np.dot(D,bigDelta)
        if DdotDelta**2 - magDsq * (magDeltasq - radius**2) < 0:
            return 100 # some large value that won't be chosen because photon has no intersection with circle
        sqrt_term = np.sqrt(DdotDelta**2 - magDsq * (magDeltasq - radius**2))/magDsq
        b_term = -DdotDelta/magDsq
        rootA = b_term - sqrt_term
        rootB = b_term + sqrt_term
        if quadrant is not False: # if in corner don't use the other 3/4ths of the circle to find distance only 2nd or 4th quadrant part
            return np.abs(rootA) if np.abs(rootA) > np.abs(rootB) else np.abs(rootB)
        return np.abs(rootA) if (rootA < 0) & cond else np.abs(rootB)

    # ARGUMENTS : 3d directional vector, 3d point, z positions of planes bottom and top, plane dimension number
    def distance_plane(self, u, o, plane, dim):                                     
        if dim==2:
            d_plane = plane[0] if u[dim] < 0 else plane[1]                    # make sure direction matches location of plane 
        else:
            d_plane = plane
        return np.abs((d_plane - o[dim])/u[dim])


    # SOLVE FOR DISTANCE LOGIC FUNCTION
    def distance_solver(self, u, o, center, radius, plane_z, corner_center, corner_radius, pmt_center, pmt_radius):
        dcircle = self.distance_circle(u,o,center,radius)                          # checks distance to circle boundary
        dplane_z = self.distance_plane(u,o,plane_z,dim=2)                          # checks distance to z boundary in general scint
        dist = dplane_z if dcircle > dplane_z else dcircle
        temp_o = o+dist*u
        PMT_cond = False
        if (pmt_center[0] > 0) & (temp_o[0] > 0) & (temp_o[1] < 0) & ((temp_o[0]**2+temp_o[1]**2) >= radius**2-1):
            dplanex = self.distance_plane(u,o,radius,dim=0)                        # checks distance to +x boundary
            dplaney = self.distance_plane(u,o,-radius,dim=1)                       # checks distance to -y boundary
            dplanez = self.distance_plane(u,o,plane_z,dim=2)                       # checks distance to z boundary inside light guide
            dcorner = self.distance_circle(u,o,corner_center, corner_radius, True) # checks distance to corner boundary
            light_guide_dist = np.min([dplanex,dplaney,dplanez,dcorner])
            temp_o = o+(light_guide_dist)*u                                   # resuse this variable
                                                                            # if close to z = zero and within PMT circle
            if (temp_o[2] < (plane_z[0]+0.01)) & (((temp_o[0]-pmt_center[0])**2+(temp_o[1]-pmt_center[1])**2) <= pmt_radius**2): 
                PMT_cond = True
            return light_guide_dist, PMT_cond
        elif (pmt_center[0] < 0) & (temp_o[0] < 0) & (temp_o[1] > 0) & ((temp_o[0]**2+temp_o[1]**2) >= radius**2-1):
            dplanex = self.distance_plane(u,o,-radius,dim=0)                       # checks distance to -x boundary
            dplaney = self.distance_plane(u,o,radius,dim=1)                        # checks distance to +y boundary
            dplanez = self.distance_plane(u,o,plane_z,dim=2)                       # checks distance to z boundary inside light guide
            dcorner = self.distance_circle(u,o,corner_center, corner_radius, True) # checks distance to corner boundary
            light_guide_dist = np.min([dplanex,dplaney,dplanez,dcorner])
            temp_o = o+(light_guide_dist)*u                                   # resuse this variable
                                                                            # if close to z = zero and within PMT circle
            if (temp_o[2] < (plane_z[0]+0.01)) & (((temp_o[0]-pmt_center[0])**2+(temp_o[1]-pmt_center[1])**2) <= pmt_radius**2): 
                PMT_cond = True
            return light_guide_dist, PMT_cond
        else:
            return dist, PMT_cond

    # PSEUDOCODE FOR EACH PHOTON INTERACTION WITH BOUNDARY
        # if random number X_1 < mean ( Reflectance s_polarization + Reflectance p_polarization ):
            # Reflect
        # else if random number X_2 < absorbption into scintillator boundary probability:
            # Absorbed and exit current particle simulation
        # else if not absorbed:
            # assume photon transmitted through boundary, 
            # absorbed by white paint and reemmitted back 
            # into scintillator with random direction given by random angles Phi_3, Theta_3
            # with constraint of z coordinate entering
    def photon_interaction(self, u, n):
        u_r = u - 2*np.dot(u, n)*n                              # u_new = u - 2 (u . n)*n
        v = u*-1 if np.dot(u,n) < 0 else u
        theta = np.arcsin(np.linalg.norm(np.cross(v,n))/(np.linalg.norm(u)*np.linalg.norm(n)))
        inside_sqrt = ((self.n_1/self.n_2)*np.sin(theta))**2
        sqrt_term = np.sqrt(1 - inside_sqrt)                    # cos(theta)_transmission
        Rs = np.abs((self.n_1*np.cos(theta) - self.n_2*sqrt_term)/(self.n_1*np.cos(theta) + self.n_2*sqrt_term))**2
        Rp = np.abs((self.n_1*sqrt_term - self.n_2*np.cos(theta))/(self.n_1*sqrt_term + self.n_2*np.cos(theta)))**2
                                                                # Determine probability of reflectance
        if np.random.random() < ((Rs+Rp)/2):                    # if random chance is high enough reflect !
            return self.normalize(u_r), True                        # return full internal reflection and not absorbed is True
                                                                # else photon is transmitted to white paint
        elif np.random.random() < self.pr_absorption:               # does it get absorbed? change probability when you get more data
            return self.normalize(u_r), False                       # not absorbed is False
        else:                                                   # no it didn't get absorbed!
            theta_new = random.uniform(-np.pi/2,np.pi/2)            # new theta direction of photon
            phi_new = random.uniform(-np.pi, np.pi)                 # new phi   direction of photon
            new_u = self.normalize(np.array([np.sin(phi_new)*np.cos(theta_new),np.sin(phi_new)*np.sin(theta_new),np.cos(phi_new)]))
            u_r = self.reemission_angle_factor*new_u + n
            return self.normalize(u_r), True                        # new small change in direction (should be random), and not absorbed is True

    # Calculate n vector for all planes and surfaces in apparatus
    def n_vec_calculate(self, o, scint_plane, light_guide_planes, corner_center, corner_radius):
        if o[2] == scint_plane[0]:                                      # bottom of scint
            return np.array([0,0,+1])
        elif o[2] == scint_plane[1]:                                    # top of scint
            return np.array([0,0,-1])
        elif o[0] == light_guide_planes[0]:                             # y plane of light guide 
            return np.array([0,light_guide_planes[0]/abs(light_guide_planes[0]),0])
        elif o[1] == light_guide_planes[1]:                             # x plane of light guide
            return np.array([light_guide_planes[1]/abs(light_guide_planes[1]),0,0])
        elif (o[0] >= corner_center[0]) & (o[1] <= corner_center[1]):   # in corner
            return self.normalize(o-corner_center)
        else:                                                           # in main scintillator
            return self.normalize(o-np.array([0,0,0]))


    #############################
    # SIMULATION FUNCTIONS
    #############################

    # PSEUDOCODE FOR PARTICLE GENERATION
        # Generate random position in circle and random direction in allowed cone
        # Walk
        # while z of particle > lowest z point of T4
        #     if point is outside of scintillator
        #          then step to next scintillator boundary
        #     for each scintillator:
        #          if point is insde of scintillator_i
        #                Generate photons if random number X_1 < Pr(scintillate)
        #                walk mean free path length and store position if still within scintillator

    def particle_path(self, t, phi_range_deg, T1_z, T1_width, T4_z, T4_width, T1_radius, T4_radius, T1_corner, T4_corner, mean_free_path, photons_per_E, prob_scint):
        theta = random.uniform(0,2*np.pi)                                                     # random theta in circle above T1
        phi = random.uniform(np.pi-phi_range_deg*np.pi/180/2,np.pi+phi_range_deg*np.pi/180/2) # phi angle pointing in -k given phi range
        maxdist = np.random.random()*self.particle_gen_area                                   # radius of generation
        round_const = self.round_to_sig(mean_free_path)
        o = np.float64((maxdist*np.cos(theta), maxdist*np.sin(theta), self.particle_gen_z))   # x, y, z of new particle
        u = np.array((np.cos(theta)*np.sin(phi),np.sin(theta)*np.sin(phi),np.cos(phi)),dtype=np.float64)
        # print(f"u=({u[0]:.2f},{u[1]:.2f},{u[2]:.2f})")
        photons = [0]                                                                         # begin photon array
        points = [o]                                                                          # current point 
        times = [t]                                                                           # current t 
        cur_o = points[-1]                                                                    # current z 
        next_o = (cur_o+mean_free_path*u).round(round_const)                                  # next z step
        inside_scint = False
        missed = 0
        while next_o[2] >= T4_z:
            if not inside_scint:
                if missed:
                    theta = random.uniform(0,2*np.pi)                                                 # reset random theta in circle above T1
                    phi = random.uniform(np.pi-phi_range_deg*np.pi/180/2,np.pi+phi_range_deg*np.pi/180/2) # reset phi angle pointing in -k given phi range
                    maxdist = np.random.random()*T1_radius/2                                          # reset random point inside half the radius of T1
                    round_const = self.round_to_sig(mean_free_path)
                    o = np.float64((maxdist*np.cos(theta), maxdist*np.sin(theta), T1_z+T1_width+2))   # reset x, y, top of T1_z+2
                    u = np.array((np.cos(theta)*np.sin(phi),np.sin(theta)*np.sin(phi),np.cos(phi)),dtype=np.float64) # reset u direction
                    photons.clear(); points.clear(); times.clear()
                    photons = [0]                                                                     # reset photon array
                    points = [o]                                                                      # reset current point 
                    times = [t]                                                                       # reset current t 
                    cur_o = points[-1]                                                                # reset current z 
                    next_o = (cur_o+mean_free_path*u).round(round_const)                              # reset next z step
                    missed = False
                distT1 = np.abs((T1_z+T1_width - cur_o[2])/u[2])
                distT4 = np.abs((T4_z+T4_width - cur_o[2])/u[2])
                dist = distT4 if next_o[2] < T1_z else distT1
                check = (cur_o+dist*u).round(round_const)
                inside_T1 = self.scint_condition(check, T1_radius, 1) | self.lg_condition(check, T1_corner, 1)
                inside_T4 = self.scint_condition(check, T4_radius, 4) | self.lg_condition(check, T4_corner, 4)
                scint_cond = inside_T4 if check[2] < T1_z else inside_T1
                # print(f"inside_T1={inside_T1} inside_T4={inside_T4}")
                # print("outer whileloop", scint_cond, next_o, dist, T4_z)          
                if scint_cond:
                    t +=  dist/self.c                                              # calculate time in ps passed
                    times.append(t)
                    points.append(points[-1]+dist*u+mean_free_path*u)
                    phot = np.random.poisson(photons_per_E)
                    if np.random.random() < prob_scint: photons.append(phot)
                    else: photons.append(0)
                    cur_o = points[-1]                                             # current point 
                    next_o = (cur_o+mean_free_path*u).round(round_const)           # next point
                    # print("z",cur_o[2],"z_1",next_o[2])
                    inside_scint = True
                else:                                                              # missed a scintillator / lightguide so throw away and restart
                    # print("missed!")
                    missed = True
                    inside_scint = False
                    continue
            for Tbottom,Ttop,Tradius,Tcorner,num in [(T1_z,T1_z+T1_width,T1_radius,T1_corner,1),(T4_z,T4_z+T4_width,T4_radius,T4_corner,4)]:
                inside_scint = (next_o[2] <= (Ttop)) & (next_o[2] >= Tbottom) & (self.scint_condition(next_o, Tradius, num) | self.lg_condition(next_o, Tcorner, num))
                while inside_scint:
                    # print("inner whileloop", inside_scint)
                    t += mean_free_path/self.c
                    times.append(t)
                    points.append(cur_o+mean_free_path*u)
                    phot = np.random.poisson(photons_per_E)
                    if np.random.random() < prob_scint: photons.append(phot)
                    else: photons.append(0)
                    cur_o = points[-1]                                             # current point 
                    next_o = (cur_o+mean_free_path*u).round(round_const)           # next point
                    inside_scint = (next_o[2] <= (Ttop)) & (next_o[2] >= Tbottom) & (self.scint_condition(next_o, Tradius, num) | self.lg_condition(next_o, Tcorner, num))
        # write to file compressed arrays float 64s
        return np.array(times, dtype=np.float64)[1:], np.array(points, dtype=np.float64)[1:], np.array(photons[1:], dtype=np.float64)

    # @profile(precision=4)
    def scintillator_monte_carlo(self, o, notabsorbed, scint_radius, scint_plane, light_guide_planes, pmt_center, pmt_radius, corner_center, corner_radius, N_max, t, keepdata):
        if keepdata: track_history = np.zeros((N_max+1,7))         # x, y history of Photon
        endpoint_dist = np.linalg.norm(o-pmt_center)
        theta = random.uniform(0,2*np.pi)             # first theta direction of photon
        phi = random.uniform(0,np.pi)                 # first phi   direction of photon
        PMT_hit_condition = False
        total_dist = 0
        dt = 0
        u = np.array([np.sin(phi)*np.cos(theta),np.sin(phi)*np.sin(theta),np.cos(phi)]) # first direction unit vector
        if keepdata: track_history[0,:] = [o[0],o[1],o[2],u[0],u[1],u[2],notabsorbed]
        i = 0
        while (i < N_max) & (not PMT_hit_condition) & (notabsorbed is True):
            ds, PMT_hit_condition = self.distance_solver(u, o, np.array([0,0,scint_plane[0]]),scint_radius, scint_plane, corner_center, corner_radius, pmt_center, pmt_radius)
            x, y, z = o+ds*u
            total_dist += np.linalg.norm(ds*u[0:2])
            o = np.array([x, y, np.abs(z) if np.abs(z-scint_plane).any() < 1e-5 else z])
            dt += np.abs(ds)/self.c                        # time taken in ps traveling in direction theta
    #         print(f"step {i}: ds={ds:.2f}cm dt={dt:.2f}ps Absorbed?={not notabsorbed} xyz =({x:.2f},{y:.2f},{z:.2f}) u=({u[0]:.2f},{u[1]:.2f},{u[2]:.2f})")
            n = self.n_vec_calculate(o, scint_plane, light_guide_planes, corner_center, corner_radius)
            u, notabsorbed = self.photon_interaction(u, n)
            if keepdata: track_history[i+1] = [x,y,z,u[0],u[1],u[2],notabsorbed]
            i+=1
        if keepdata:
            if (i < N_max):
                track_history = track_history[:i+1,:]
            return PMT_hit_condition, (t+dt), track_history
        else:
            return PMT_hit_condition, (t+dt), total_dist, endpoint_dist, i, dt

    # PMT SIMULATION
    def photontoElectrons(self, photons):
        e = 0.
        for i in range(int(photons)):
            if np.random.random()<self.QE: # Main Monte Carlo 
                e+=1
        for dynode in range(self.n_dynodes-1):
            delta_voltage = self.V[dynode+1]-self.V[dynode]
            e += np.random.poisson(e*delta_voltage/self.E_per_electron)
        return e

    #############################
    # RUN SIMULATION 
    #############################
    def particle_task(self, mult, q1, q2):
        times, points, photons = self.particle_path(t=self.t_initial+self.seperation_time*mult, phi_range_deg=self.particle_init_angle_range, T1_z=self.T1z, T1_width=self.T1_width, 
                                                T4_z=self.T4z, T4_width=self.T4_width, T1_radius=self.T1_radius, T4_radius=self.T4_radius, T1_corner=[self.T4_radius,-self.T4_radius],
                                                T4_corner=[self.T1_radius,-self.T1_radius], mean_free_path=self.mean_free_path_scints, 
                                                photons_per_E=self.photons_produced_per_MeV, prob_scint=self.pr_of_scintillation)
        T1points = points[points[:,2] >= self.T1z]
        T1times = times[points[:,2] >= self.T1z]
        T1photons = photons[points[:,2] >= self.T1z]
        T1part_ids = np.repeat(mult, len(T1times))
        T4points = points[points[:,2] < self.T1z]
        T4times = times[points[:,2] < self.T1z]
        T4photons = photons[points[:,2] < self.T1z]
        T4part_ids = np.repeat(mult, len(T4times))
        q1.put(np.repeat(np.c_[T1points,T1times,T1part_ids],T1photons.astype(int), axis=0))
        q2.put(np.repeat(np.c_[T4points,T4times,T4part_ids],T4photons.astype(int), axis=0))


    def scint_taskT1(self, xpoint, ypoint, zpoint, time_i):
        # READ A SMALL FILE WITH LITTLE MiB --> compressed file output
        point_i = np.hstack((xpoint,ypoint,zpoint))
        return self.scintillator_monte_carlo(point_i, notabsorbed=True, scint_radius=self.T1_radius, 
                                                        scint_plane=np.array([self.T1z,self.T1top]),  
                                                        light_guide_planes=[self.T1_radius,-self.T1_radius], 
                                                        pmt_center=self.PMT1_center, pmt_radius=self.PMT1_radius, corner_center=self.T1_corner_center,
                                                        corner_radius=self.T1_corner_radius, N_max=self.max_simulated_reflections, t=time_i, keepdata=False)
    def scint_taskT4(self, xpoint, ypoint, zpoint, time_i):
        point_i = np.hstack((xpoint,ypoint,zpoint))
        return self.scintillator_monte_carlo(point_i, notabsorbed=True, scint_radius=self.T4_radius, 
                                                        scint_plane=np.array([self.T4z,self.T4top]),
                                                        light_guide_planes=[-self.T4_radius,+self.T4_radius], 
                                                        pmt_center=self.PMT4_center, pmt_radius=self.PMT4_radius, corner_center=self.T4_corner_center,
                                                        corner_radius=self.T4_corner_radius, N_max=self.max_simulated_reflections, t=time_i, keepdata=False)
   
    #######################################  P O O L #############################################################################
    # """Run simulation with default 1 particle or arg[0] as number of particles and a time seperation of 'delta_t'=1e-5"""
    # # @profile(precision=4)
    # def run(self, *arg, **kwargs):
        import gc
        freeze_support()
        if arg:
            self.num_particles = int(arg[0])
            print(f"Generating {self.num_particles} particles now...")
        else:
            self.num_particles = 1
            print(f"Generating {self.num_particles} particle now...")
        self.seperation_time = kwargs.get('delta_t', self.seperation_time) # in ps
        logstarttime = perf_counter()


        
        # FIND PARTICLE PATH
        

        with Pool(processes=cpu_count()-1) as pool:
            pool.starmap(self.particle_task, (range(self.num_particles),))
        logendparticle = perf_counter()
        N = np.sum(photons)
        print("Photons generated", N)
        times = np.asarray(times); points = np.asarray(points); photons = np.asarray(photons); particleID = np.asarray(particleID)
        # RETURNS A FILE
        # SPLIT HERE
        # RUN #2
        

        # SIMULATE EACH PHOTON PATH IN BOTH SCINTILLATORS
        # Gather TOF data
        T1_input_times = []
        T4_input_times = []
        # Gather Extra Data for analysis
        self.T1_prop_dist = []
        self.T4_prop_dist = []
        self.T1_endpoint_dist = []
        self.T4_endpoint_dist = []
        self.T1_prop_times = []
        self.T4_prop_times = []
        self.T1_interactions = []
        self.T4_interactions = []
        self.T1_part_ids = []
        self.T4_part_ids = []
        T1points = (points[:])[points[:,2] >= self.T1z]
        T1times = (times[:])[points[:,2] >= self.T1z]
        T1photons = (photons[:])[points[:,2] >= self.T1z]
        T1part_ids = (particleID[:])[points[:,2] >= self.T1z]
        T1part_ids = np.repeat(T1part_ids, T1photons.astype(int), axis=0) # big id bank
        T4points = (points[:])[points[:,2] < self.T1z]
        T4times = (times[:])[points[:,2] < self.T1z]
        T4photons = (photons[:])[points[:,2] < self.T1z]
        T4part_ids = (particleID[:])[points[:,2] < self.T1z]
        T4part_ids = np.repeat(T4part_ids, T4photons.astype(int), axis=0) # big id bank
        print(f"Photons in T1: {np.sum(T1photons)} and Photons in T4: {np.sum(T4photons)}")
        del times; del points; del photons; # remove copies
        gc.collect()
        logstartphoton = perf_counter()

        # check this link https://stackoverflow.com/questions/14749897/python-multiprocessing-memory-usage
        with Pool(processes=cpu_count()) as pool: # this way of making the pool causes all the data to copy! 
            print("T1 Photon Propagation working...")
            T1res = pool.starmap(self.scint_taskT1, np.repeat(np.c_[T1points,T1times],T1photons.astype(int), axis=0))
            print("Done!")
            print("T4 Photon Propagation working...")
            T4res = pool.starmap(self.scint_taskT4, np.repeat(np.c_[T4points,T4times],T4photons.astype(int), axis=0))
            print("Done!")
            print("Unzipping reuslts into arrays...")
            for (T1hit_PMT, T1travel_time, T1tot_dist, T1endpt, T1bounces, T1prop),T1part_id in zip(T1res, T1part_ids): # check if moving starmap here helps
                if T1hit_PMT:
                    T1_input_times.append(T1travel_time)
                    self.T1_prop_dist.append(T1tot_dist)
                    self.T1_endpoint_dist.append(T1endpt)
                    self.T1_prop_times.append(T1prop)
                    self.T1_interactions.append(T1bounces)
                    self.T1_part_ids.append(T1part_id)
            for (T4hit_PMT, T4travel_time, T4tot_dist, T4endpt, T4bounces, T4prop),T4part_id in zip(T4res, T4part_ids): # check if moving starmap here helps
                if T4hit_PMT:
                    T4_input_times.append(T4travel_time)
                    self.T4_prop_dist.append(T4tot_dist)
                    self.T4_endpoint_dist.append(T4endpt)
                    self.T4_prop_times.append(T4prop)
                    self.T4_interactions.append(T4bounces)
                    self.T4_part_ids.append(T4part_id)
        logendtime = perf_counter()
        # PRINT RESULTS
        print("TIME ANALYSIS:")
        pgtime = timedelta(seconds=logendparticle-logstarttime)
        phtime = timedelta(seconds=logendtime-logstartphoton)
        ttime = timedelta(seconds=logendtime-logstarttime)
        print(f"Generation of Particles     {str(pgtime)}")
        print(f"Simulation of Photon Travel {str(phtime)}")
        print(f"Total Time Elapsed:         {str(ttime)}")
        print("RESULTS SUMMARY:")
        print("HITS on T1",len(T1_input_times))
        print("RATIO T1   total photons", np.sum(T1photons), "total incident photons", len(T1_input_times), f"ratio={np.sum(T1photons)/len(T1_input_times):.2f}")
        print("HITS on T4",len(T4_input_times))
        print("RATIO T4   total photons ", np.sum(T4photons),"total incident photons", len(T4_input_times), f"ratio={np.sum(T4photons)/len(T4_input_times):.2f}")
        print("DISTANCE: ")
        del T1points; del T1times; del T1photons; del T4points; del T4times; del T4photons; # remove unused variables
        gc.collect()
        # print(T4_input_times)
        # BEGIN SIMULATING PMT PULSE
        signals_channelT1 = []
        signals_channelT4 = []
        output_times_channelT1 = []
        output_times_channelT4 = []
        signals = []
        output_times = []
        for t in T1_input_times:
            pmtSignal_i = self.photontoElectrons(1)
            output_times.append(self.pmt_electron_travel_time+t)
            output_times_channelT1.append(self.pmt_electron_travel_time+t)
            signals.append(pmtSignal_i)
            signals_channelT1.append(pmtSignal_i)
        for t in T4_input_times:
            pmtSignal_i = self.photontoElectrons(1)
            output_times.append(self.pmt_electron_travel_time+t)
            output_times_channelT4.append(self.pmt_electron_travel_time+t)
            signals.append(pmtSignal_i)
            signals_channelT4.append(pmtSignal_i)

        # CONVERTION Electron count to Current and save in array
        self.signals = np.array(signals) * self.q / 1e-12 * self.artificial_gain # divided by 1ps 
        self.output_times = np.array(output_times)
        self.signals_channelT1 = np.array(signals_channelT1) * self.q / 1e-12 * self.artificial_gain
        self.signals_channelT4 = np.array(signals_channelT4) * self.q / 1e-12 * self.artificial_gain * 0.6 # factor to limit pulses to 50miliamps and stop contant comparator firing. however, current should be smaller from Quantum Efficiency and current should be larger from 3kV potential difference across PMT dynodes instead of current 1kV potential difference
        self.output_times_channelT1 = np.array(output_times_channelT1)
        self.output_times_channelT4 = np.array(output_times_channelT4)
    #######################################  P O O L #############################################################################

    # Output function
    def to_csv(self, **kwargs):
        from scipy.stats import norm
        output_extra = kwargs.get('extra_data_only', False)
        output_both = kwargs.get('output_both', False)
        # OUTPUT FORMATTING
        if output_extra or output_both:
            print("Exporting Extra Data...")
            dft1 = pd.DataFrame({'T1_part_ids':self.T1_part_ids,'time':self.output_times_channelT1,'T1_prop_dist':self.T1_prop_dist,'T1_endpoint_dist':self.T1_endpoint_dist, 'T1_prop_times':self.T1_prop_times, 'T1_interactions':self.T1_interactions})
            dft4 = pd.DataFrame({'T4_part_ids':self.T4_part_ids,'time':self.output_times_channelT4,'T4_prop_dist':self.T4_prop_dist,'T4_endpoint_dist':self.T4_endpoint_dist, 'T4_prop_times':self.T4_prop_times, 'T4_interactions':self.T4_interactions})
            dft1.to_csv('monte_carlo_extradata'+str(self.num_particles)+'chT1_'+str(datetime.now().strftime('%m_%d_%Y'))+'.txt') # default sep=','
            dft4.to_csv('monte_carlo_extradata'+str(self.num_particles)+'chT4_'+str(datetime.now().strftime('%m_%d_%Y'))+'.txt') # default sep=','
            if not output_both:
                return
        print("Exporing to 2 channels...")
        # for each channel
        for time,signal,ch in zip([self.output_times_channelT1,self.output_times_channelT4],[self.signals_channelT1,self.signals_channelT4],[1,4]):

            # from io import StringIO
            # from csv import writer 
            # output = StringIO()
            # csv_writer = writer(output)
            
            print("Smoothing Signals...")
            t_binned = [0.] # left edges of bins
            y_binned = [0.]
            for i,y in enumerate(signal):
                # print(f"i={i},t[{i}]={time[i]} y[{i}]={y}")
                lower_bound = max(time[i]-2*self.sigma_smoothing,0) # 2 sigma away backward
                upper_bound = min(time[i]+2*self.sigma_smoothing,max(time)+2*self.sigma_smoothing) # 2 sigma away forward
                # MAKE NEW DATA CENTERED AROUND PULSE
                if lower_bound < max(t_binned): # if already binned
                    lower_bound = t_binned[np.digitize(lower_bound, t_binned)]+self.output_bin_width/2
                cur_x = np.arange(lower_bound,upper_bound,self.output_bin_width)+self.output_bin_width/2
                # print(f"cur_x from {lower_bound}-->{upper_bound}", cur_x)
                # ADD DATA IF NEEDED
                for x in cur_x:
                    if x > max(t_binned): 
                        t_binned.append(x)
                        y_binned.append(0)
                    elif (np.digitize(x, t_binned)-1 > 0) and (np.digitize(x, t_binned) < len(t_binned)):
                        index = np.digitize(x, t_binned)
                        if abs(t_binned[index]-t_binned[index-1]) > self.output_bin_width:
                            t_binned.insert(index, x) # check if need -1 or just np.digitize()
                            y_binned.insert(index, 0) # check 
                # GET INDICIES
                index_lower = [i for i,t in enumerate(t_binned) if t >= lower_bound][0] # left edge in time binned
                index_upper = [i for i,t in enumerate(t_binned) if t <= upper_bound][-1] # right edge in time binned
                # GAUSSIAN SMOOTH
                gaussian = norm.pdf(t_binned[index_lower:index_upper], loc=time[i], scale=self.sigma_smoothing)*self.sigma_smoothing*y/4
                # ADD TO CORRECT BINS
                for i,y_add in enumerate(gaussian):
                    if y_binned[index_lower+i]+y_add < self.max_pmt_current_output:
                        y_binned[index_lower+i] += y_add
                    else:
                        y_binned[index_lower+i] = self.max_pmt_current_output

            df = pd.DataFrame({'time':t_binned,'current':y_binned}).sort_values(by=['time'])
            print("Formatting PWL dataframe...")
            fill_data = []                                                                      # declare empty array
            # begin padding data at time 1/5th bin width before first time stamp
            fill_data.append([df['time'].iloc[0]-self.output_bin_width/5,0])                    # add zero at beginning
            for i in range(len(df['time'])-1):                                                        # for each time index
                if abs(df['time'].iloc[i]-df['time'].iloc[i+1]) > self.output_bin_width:        # if dt between signals is greater than minimum bin width
                    fill_data.append([df['time'].iloc[i]+self.output_bin_width/5,0])            # place zero after current signal
                    fill_data.append([df['time'].iloc[i+1]-self.output_bin_width/5,0])          # place zero before next signal
            fill_data.append([df['time'].iloc[-1]+self.output_bin_width/5,0])                   # add zero at end
            fill_data = np.array(fill_data)
            fill = pd.DataFrame(fill_data, columns=['time','current'])
            df = pd.concat([fill, df], ignore_index=True).sort_values(by=['time']).reset_index(drop=True)
            df['time'] = df['time']/1e12
            df = df[['time', 'current']] # need this for LTSpice PWL current input file to work
            df.to_csv('monte_carlo_input'+str(self.num_particles)+'ch'+str(ch)+'_'+str(datetime.now().strftime('%m_%d_%Y'))+'.txt', float_format='%.13f', header=False, index=False, sep=' ') # PWL file formatting
        print("Done!")

    """
      Alternate ToF Method Assuming Seperation Width and Known # of Particles
      Uses rising edge time to compare for Time-of-Flight calculations like CMOS chip
    """
    def time_at_thresh(self, rawtime, rawVoltage, num, thresh, ch):
        out = []
        grad = np.gradient(rawVoltage) # find gradients on all data
        limit = (grad > 0) & (grad >= 0.1) # positive slope bigger than 0.1
        dtime = rawtime[limit]
        dtvoltage = rawVoltage[limit]
        tdiff = np.diff(dtime)
        first_particle = True
        condition_0 = (grad > 0) & (grad < 0.001)
        condition = tdiff > self.seperation_time/1e12/10 # check if next point is 10ns away
        count = 0
        start_index = 0
        for i in range(len(tdiff)): # for number of particles we expect
            if count > num-1:
                return np.array(out)
            if condition[i] or condition_0[i]: # if condition is true at index i
                if first_particle:
                    condition_0 = False
                    first_particle = False
                times = dtime[start_index:i+1] # take snippet of time from starting index flag to index i
                Voltages = dtvoltage[start_index:i+1]
                start_index = i+1 # reset flag to next position
                if len(times) < 1 or len(Voltages) < 1: # if no particle here then skip
                    continue
                m, b = np.polyfit(times,Voltages, deg=1) # find linear fit
                # if deg=1 returns two params slope m and y-intercept b
                # now use slope and intercept to solve for x value given our mid value y
                # y = mx + b  --> x = (y - b) / m
                out.append( (thresh - b) / m )
                count +=1 # count particle!
            
        print("Ch",ch,"counted",count,"particles!")
        if count < num: 
            print(f"Note: Counted less particles than the expected {num}")
            print("Check LTSpice that all particles were simulated.")
        return np.array(out)

    def ToF_finalize(self, tofch1, tofch4, time_limit=10e-9):
        print("ch1 length", len(tofch1))
        print("ch4 length", len(tofch4))
        out = []
        i = 0; j = 0
        lim = time_limit if time_limit is not None else 10e-9
        while (i < len(tofch1)) and (j < len(tofch4)):
            check = tofch4[j] - tofch1[i]
            if abs(check) < lim:
                out.append(abs(check))
                i+=1
                j+=1
            elif (i+1 < len(tofch1)) and (j+1 < len(tofch4)) and check < 0:
                j+=1
            else: #check < 0
                i+=1
        print("finished calculating,", len(out), "particles")
        self.FinalToF = np.array(out)
        # return np.array(out)
    
    """LTSpice Command to Analyze, Simulate and Calculate TOF"""
    def ltspice(self, filedate=None, filenum=None, filesep=None):
        print("\n##################################")
        print("Running LTSpice on each channel...")
        print("###################################\n")
        import os
        from PyLTSpice import SimCommander, RawRead # Use version 3.1 by pip3 install PyLTSpice==3.1
        # Make the .net file (netlist) by opening file first then saving a seperate text file
        LTC = SimCommander("PHAReduced_sim.net", parallel_sims=cpu_count()-1)
        # When running this file, two LTSpice libaries must be in same folder location:
        # LTC1.lib and LTC7.lib
        ch1ToF = 0 # declare for scope
        ch4ToF = 0 # declare for scope
        # Save the filenames of the inputs to LTSpice (Need to be Same Day and # of particles)
        # 'monte_carlo_input<X>ch1_<MM>_<DD>_<YYYY>.txt' is the format where X is # of particles if manual input is desired
        # filename_ch1 = os.path.abspath('monte_carlo_input<X>ch1_<MM>_<DD>_<YYYY>.txt')
        date = datetime.now().strftime('%m_%d_%Y') # Defaults
        num_part = self.num_particles
        sep_part = self.seperation_time
        if filedate is not None: # Take input given correct format
            date = filedate
        if filenum is not None: # Take input given correct integer number
            num_part = int(filenum)
        if filesep is not None:
            sep_part = int(filesep)
        filename_ch1 = os.path.abspath('monte_carlo_input'+str(num_part)+'ch1_'+str(date)+'.txt')
        filename_ch4 = os.path.abspath('monte_carlo_input'+str(num_part)+'ch4_'+str(date)+'.txt')
        for filename,strname in zip([filename_ch1,filename_ch4],['ch1','ch4']):
            print('PWL file='+str(filename))
            LTC.set_element_model('I1', 'PWL file='+str(filename))
            LTC.add_instructions("; Simulation settings", f".tran 0 {int(round(num_part*sep_part/1e6,0))}.5u 0 0.002u") # fix this to adjust for time seperation
            # print(LTC.get_component_info('I1')) # to check if correctly set
            LTC.run(run_filename=f'PHAReduced_{strname}.net')
            LTC.wait_completion()
            print('Successful/Total Simulations: ' + str(LTC.okSim) + '/' + str(LTC.runno))
            # Now read the output
            LTR = RawRead(f"PHAReduced_{strname}.raw")
            # print(LTR.get_trace_names()) # check the outputs
            # print(LTR.get_raw_property()) # what properies does the simulation have
            # get trace gets the output waveform, get wave retrieves data from waveform object
            t = LTR.get_trace('time').get_wave() 
            compOut = LTR.get_trace('V(compout)').get_wave()
            # input ndarrays into DataFrame and fix weird negative time values
            df = pd.DataFrame({'t':np.abs(t),'V':compOut}).sort_values(by='t')
            df.to_csv('output'+str(num_part)+strname+'_'+str(date)+'.txt', header=False, index=False)
            # implement csv creation!
            # Clean up extra files
            os.remove(f"PHAReduced_{strname}.log")
            os.remove(f"PHAReduced_{strname}.op.raw")
            os.remove(f"PHAReduced_{strname}.raw")
            os.remove(f"PHAReduced_{strname}.net")
            # Remove LTSpice Object
            del LTR
       
    """ToF load LTSpice output function and call time_at_thresh and ToF_finalize""" 
    def calc_ToF(self, filedate=None, filenum=None):
        import os
        # Make final calulcation all time of flight data
        date = datetime.now().strftime('%m_%d_%Y') # Defaults
        num_part = self.num_particles
        if filedate is not None: # Take input given correct format
            date = filedate
        if filenum is not None: # Take input given correct integer number
            num_part = int(filenum)
        filename_ch1 = os.path.abspath('output'+str(num_part)+'ch1_'+str(date)+'.txt')
        filename_ch4 = os.path.abspath('output'+str(num_part)+'ch4_'+str(date)+'.txt')
        ch1 = pd.read_csv(filename_ch1, names=['t', 'V'], sep=',')
        ch4 = pd.read_csv(filename_ch4, names=['t', 'V'], sep=',')
        ch1ToF = self.time_at_thresh(ch1['t'],ch1['V'], num_part, self.CMOS_thresh, 1)
        ch4ToF = self.time_at_thresh(ch4['t'],ch4['V'], num_part, self.CMOS_thresh, 4)
        self.ToF_finalize(ch1ToF,ch4ToF) # Calculated correct time of flight
        print(pd.DataFrame(self.FinalToF).describe())

    """ToF save result data to a csv file"""
    def save_ToF(self, filename=None):
        # Default
        date = datetime.now().strftime('%m_%d_%Y')
        num_total = self.num_particles
        counted = len(self.FinalToF)
        file = 'result_'+str(counted)+'_of_'+str(num_total)+'_'+str(date)+'.txt'
        if filename is not None: # if special name use it
            file = filename
        # Output using DataFrame format and column title
        pd.DataFrame({'Time-of-Flight [s]':self.FinalToF}).to_csv(file, index=False)
    