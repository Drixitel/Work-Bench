# Testing by Michelle P 9/4/23 - MAIN FILE
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

# Module 
from mod import *



#######################################  P O O L #############################################################################
"""Run simulation with default 1 particle or arg[0] as number of particles and a time separation of 'delta_t'=1e-5"""
# @profile(precision=4)
def run(sim, *arg, **kwargs):
    import gc

    freeze_support()

    if arg:
        # Multi particle 
        sim.num_particles = int(arg[0])
        print(f"Generating {sim.num_particles} particles now...")
    else:
        # Single particle 
        sim.num_particles = 1
        print(f"Generating {sim.num_particles} particle now...")

    sim.seperation_time = kwargs.get('delta_t', sim.seperation_time) # in ps
    logstarttime = perf_counter()


    
    # FIND PARTICLE PATH via multiprocessing 
    
    with Pool(processes=cpu_count()-1) as pool:
        pool.starmap(sim.particle_task, ( range(sim.num_particles) , )) 

    pool.close()
    pool.join()

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
    sim.T1_prop_dist = []
    sim.T4_prop_dist = []
    sim.T1_endpoint_dist = []
    sim.T4_endpoint_dist = []
    sim.T1_prop_times = []
    sim.T4_prop_times = []
    sim.T1_interactions = []
    sim.T4_interactions = []
    sim.T1_part_ids = []
    sim.T4_part_ids = []
    T1points = (points[:])[points[:,2] >= sim.T1z]
    T1times = (times[:])[points[:,2] >= sim.T1z]
    T1photons = (photons[:])[points[:,2] >= sim.T1z]
    T1part_ids = (particleID[:])[points[:,2] >= sim.T1z]
    T1part_ids = np.repeat(T1part_ids, T1photons.astype(int), axis=0) # big id bank
    T4points = (points[:])[points[:,2] < sim.T1z]
    T4times = (times[:])[points[:,2] < sim.T1z]
    T4photons = (photons[:])[points[:,2] < sim.T1z]
    T4part_ids = (particleID[:])[points[:,2] < sim.T1z]
    T4part_ids = np.repeat(T4part_ids, T4photons.astype(int), axis=0) # big id bank
    print(f"Photons in T1: {np.sum(T1photons)} and Photons in T4: {np.sum(T4photons)}")
    del times; del points; del photons; # remove copies
    gc.collect()
    logstartphoton = perf_counter()

    # check this link https://stackoverflow.com/questions/14749897/python-multiprocessing-memory-usage
    with Pool(processes=cpu_count()) as pool: # this way of making the pool causes all the data to copy! 
        print("T1 Photon Propagation working...")
        T1res = pool.starmap(sim.scint_taskT1, np.repeat(np.c_[T1points,T1times],T1photons.astype(int), axis=0))
        print("Done!")

        T1res.close()
        T1res.join()

        print("T4 Photon Propagation working...")
        T4res = pool.starmap(sim.scint_taskT4, np.repeat(np.c_[T4points,T4times],T4photons.astype(int), axis=0))
        print("Done!")

        T4res.close()
        T4res.join()

        print("Unzipping results into arrays...")
        for (T1hit_PMT, T1travel_time, T1tot_dist, T1endpt, T1bounces, T1prop),T1part_id in zip(T1res, T1part_ids): # check if moving starmap here helps
            if T1hit_PMT:
                T1_input_times.append(T1travel_time)
                sim.T1_prop_dist.append(T1tot_dist)
                sim.T1_endpoint_dist.append(T1endpt)
                sim.T1_prop_times.append(T1prop)
                sim.T1_interactions.append(T1bounces)
                sim.T1_part_ids.append(T1part_id)
        for (T4hit_PMT, T4travel_time, T4tot_dist, T4endpt, T4bounces, T4prop),T4part_id in zip(T4res, T4part_ids): # check if moving starmap here helps
            if T4hit_PMT:
                T4_input_times.append(T4travel_time)
                sim.T4_prop_dist.append(T4tot_dist)
                sim.T4_endpoint_dist.append(T4endpt)
                sim.T4_prop_times.append(T4prop)
                sim.T4_interactions.append(T4bounces)
                sim.T4_part_ids.append(T4part_id)
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
        pmtSignal_i = sim.photontoElectrons(1)
        output_times.append(sim.pmt_electron_travel_time+t)
        output_times_channelT1.append(sim.pmt_electron_travel_time+t)
        signals.append(pmtSignal_i)
        signals_channelT1.append(pmtSignal_i)
    for t in T4_input_times:
        pmtSignal_i = sim.photontoElectrons(1)
        output_times.append(sim.pmt_electron_travel_time+t)
        output_times_channelT4.append(sim.pmt_electron_travel_time+t)
        signals.append(pmtSignal_i)
        signals_channelT4.append(pmtSignal_i)

    # CONVERTION Electron count to Current and save in array
    sim.signals = np.array(signals) * sim.q / 1e-12 * sim.artificial_gain # divided by 1ps 
    sim.output_times = np.array(output_times)
    sim.signals_channelT1 = np.array(signals_channelT1) * sim.q / 1e-12 * sim.artificial_gain
    sim.signals_channelT4 = np.array(signals_channelT4) * sim.q / 1e-12 * sim.artificial_gain * 0.6 # factor to limit pulses to 50miliamps and stop contant comparator firing. however, current should be smaller from Quantum Efficiency and current should be larger from 3kV potential difference across PMT dynodes instead of current 1kV potential difference
    sim.output_times_channelT1 = np.array(output_times_channelT1)
    sim.output_times_channelT4 = np.array(output_times_channelT4)
#######################################  P O O L #############################################################################

if __name__ == "__main__": 

    # Create instance 
    sim_instance = Simulation()

    #run
    run(sim_instance, 1)