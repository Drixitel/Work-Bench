# Testing by Michelle P 9/4/23
# Keep Multiprocessing 
#   add .join and .close 

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

# Class Simulation: self.function()/self.variable() called within itself
### No self calls 
#   init(self) : constants 
#   round_to_sig(self,float) : int 
#   normalize(self, float): float
#   lg_condition(self, x1, x2, x3): y
#   distance_circle(self,x1,x2,x3,x4,x5): ?
#   distance_plane(self, x1,x2,x3,x4): ?

### Calls self Constants ONLY
#   scint_condition(self, x1,x2,x3): y
#   photontoElectrons(self, x): float ? 

### Calls self.other_functions
#   distance_solver(self, x1,x2,x3,x4,x5,x6,x7,x8,x9): ?,Bool
#   - distance_circle(self,x1,x2,x3,x4,x5): ?
#   - distance_plane(self, x1,x2,x3,x4): ?

#   photon_interaction(self, x1,x2): ?,Bool
#   - normalize(self, float): float
#   - self.constants 

#   n_vec_calculate(self, x1,x2,x3,x4,x5): array ? 
#   - normalize(self, float): float

#   particle_path(self, x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x12,x13): array ? 
#   - round_to_sig(self,float) : int 
#   - self.constants 
#   - scint_condition(self, x1,x2,x3): y
#   - lg_condition(self, x1, x2, x3): y

#   scintillator_monte_carlo(self,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x12 ): bool, constants ... 
#   - distance_solver(self, x1,x2,x3,x4,x5,x6,x7,x8,x9): ?,Bool
#   - n_vec_calculate(self, x1,x2,x3,x4,x5): array ? 
#   - photon_interaction(self, x1,x2): ?,Bool

#   particle_task(self, x1,x2,x3): void 
#   - particle_path(self, x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x12,x13): array ? 

#   scint_taskT1(self, x1,x2,x3,x4): bool, constants... 
#   - scintillator_monte_carlo(self,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x12 ): bool, constants ... 

#   scint_taskT4(self, x1,x2,x3,x4): bool, constants... 
#   - scintillator_monte_carlo(self,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x12 ): bool, constants ... 


#   Pool  ###################################################
#   run(self, x1*,x2*): void 
#   - self.constants 
#   - particle_task(self, x1,x2,x3): void 
#   - scint_taskT1(self, x1,x2,x3,x4): bool, constants... 
#   - scint_taskT4(self, x1,x2,x3,x4): bool, constants... 
#   - photontoElectrons(self, x): float ? 
# ###########################################################

# Plotting and other functions without other function calls 

#   time_at_thresh(self, x1,x2,x3,x4,x5): array ? 
#   ToF_finalize(self, x1,x2,x3): void
#   ltspice(self, x1,x2,x3): void 
#   calc_ToF(self, x1,x2): void
#   save_ToF(self, x1): void 
#   to_csv(self, x1*): cases 2(?, void)