# Testing by Michelle P 9/4/23
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


     
