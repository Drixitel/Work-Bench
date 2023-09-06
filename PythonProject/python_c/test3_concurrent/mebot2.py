from multiprocessing import Pool, cpu_count
import mod as Mebot
import time
import numpy as np


def main():
    with Pool(processes=cpu_count() - 1) as pool:
       iter_of_results = pool.starmap_async( Mebot.simulate , [[1000,2/3]]*10_000 ).get()
    return iter_of_results

if __name__ == "__main__" :

    # p = Pool(48)
    
    T = time.time()
    
    results = main()
    
    print( time.time() - T )
    
    print( np.average( results ) )
    print( len(results) )