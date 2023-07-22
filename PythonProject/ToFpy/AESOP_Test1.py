# Testing by Michelle P
# Original file by Liam Branch

import numpy as np
import pandas as pd
from tqdm import tqdm # Progress bar
import random # Generator 
from time import perf_counter # float value of time in seconds 
from datetime import timedelta, datetime # microsecond resolution for deltas (time,date)
from multiprocessing import Pool, cpu_count, freeze_support
from memory_profiler import profile

from typing import Union, List
from numpy.typing import ArrayLike

class Simulation:
    
    def __init__(self): 
        # This is a constructor
        #   it sets up all the constants and defaults 
        #   There are NO functions here
        #   it also sends prints to the user about them
        #############################
        # CONSTANTS
        #############################
        self.c: float = 0.0299792/1.58 # Speed of Light in cm / ps
        self.q: float = 1.60217663e-19 # charge of electron columbs
        # CONSTRAINT n_1 <= n_2
        # SIMULATOR FIELDS
        self.n_1: float = 1.000293 # Sample index of refraction of air
        self.n_2: float = 1.58 # 1.58 for EJ-200
        self.T3z: float=0 #cm is the bottom of T3
        self.T1z: float=33.782 #cm is the bottom of T1
        self.T4z: float=-28.07297 #cm is the bottom of T4
        self.T1_radius: float = 13 #cm
        self.T4_radius: float = 18 #cm
        self.T1_width: float = 0.5 #cm
        self.T4_width: float = 1 #cm
        self.T1top: float = self.T1z+self.T1_width
        self.T4top: float = self.T4z+self.T4_width
        self.T1_corner_radius: float = self.T1_width*4
        self.T4_corner_radius: float = self.T4_width*4
        self.T1_corner_center: List[float] = [self.T1_radius-self.T1_corner_radius,self.T1_corner_radius-self.T1_radius, self.T1_radius]
        self.T4_corner_center: List[float] = [self.T4_corner_radius-self.T4_radius, self.T4_radius-self.T4_corner_radius, self.T4_radius]
        self.PMT1_center: List[float] = [self.T1_radius-4*0.5,-self.T1_radius+4*0.5,self.T1z]
        self.PMT4_center: List[float] = [-self.T4_radius+4*0.5,self.T4_radius-4*0.5,self.T4z]
        self.xPMT4: float = 9.5*np.cos(np.radians(110))*2.54
        self.yPMT4: float = 9.5*np.sin(np.radians(110))*2.54
        self.xPMT1: float = 8.*np.cos(np.radians(-45))*2.54 # x2PMT1=8.*np.cos(np.radians(-53.72))*2.54 For test
        self.yPMT1: float = 8.*np.sin(np.radians(-45))*2.54 # y2PMT1=8.*np.sin(np.radians(-53.72))*2.54 For test
        self.PMT1_radius: float = 4.6/2 #cm need to change this to 46 milimeters or 0.046 cm
        self.PMT4_radius: float = 4.6/2 #cm 
        # PMT SIGNAL GENERATION FIELDS 
        self.n_dynodes: int = 8
        self.V: List[float] = np.linspace(150,850,self.n_dynodes)
        # self.V = [150,300,350,600,750,850]
        self.E_per_electron: float = 20
        self.QE: float = 1 #0.23
        self.sigma_smoothing: float = 400 #ps
        self.t_initial: float = 0 #ps
        self.particle_init_angle_range: float = 40 #degrees
        self.particle_gen_area: float = self.T1_radius
        self.particle_gen_z: float = self.T1z+self.T1_width + 2 #cm
        self.mean_free_path_scints: float = 24e-5 #cm or 80 micro meters
        self.photons_produced_per_MeV: float = 10 # true value is closer to 10000 per 1MeV
        self.pr_of_scintillation: float = 0.8
        self.max_simulated_reflections: float = 40
        self.pmt_electron_travel_time: float = 0 # approx 16 ns
        self.artificial_gain: float = 1 # gain factor
        self.max_pmt_current_output: float = 80e-3 # mA
        self.pr_absorption: float = 0.1 # probability of boundary absorbing
        self.seperation_time: float = 1e5 # ps 
        self.output_bin_width: float = 100 # ps
        self.num_particles = 1 # default Muons
        self.CMOS_thresh: float = 1.5 # V for rising edge detector
        self.reemission_angle_factor: float = 0.9 # range [0,1] --> cone from [-pi,pi]
        
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
    def round_to_sig(self, x: float) -> int:
        return -int(np.floor(np.log10(np.abs(x))))

    # NORMALIZE A VECTOR
    def normalize(self, x: ArrayLike) -> ArrayLike:
        x /= np.linalg.norm(x) # divide by norm 
        return x
    
    # LIGHT GUIDE CONDITION
    def lg_condition(self, corner_pt: List[float], scint_corner: List[float], scint_num: int) -> bool:
        ret: bool
        if scint_num == 4:
            ret = (corner_pt[0] > 0) & (corner_pt[0] < scint_corner[0]) & (corner_pt[1] < 0) & (corner_pt[1] > scint_corner[1])
        else:
            ret = False
        return ret

    # SCINT RADIUS CONDITION
    def scint_condition(self, corner_pt: np.array, scint_radius: float, scint_num: int) -> bool:
        ret = bool
        if scint_num == 4:
            ret = np.sqrt(np.sum(corner_pt[0:2]**2)) < self.T4_radius
        else:
            ret = np.sqrt(np.sum(corner_pt[0:2]**2)) < self.T1_radius
        return ret
    

     
