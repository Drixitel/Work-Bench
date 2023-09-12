import concurrent.futures as cf
import time
import numpy as np
import mod as Mebot

nums = [[1000,2/3]]*10_000



if __name__ == "__main__" :

    T = time.time()
    with cf.ProcessPoolExecutor(max_workers=5) as executor :
        results = [executor.submit( Mebot.run_simulation, num) for num in nums]
        # results = executor.map(Mebot.run_simulation, nums)

    print( time.time() - T )
    # print(type(results))
    # print(type(results[0]))
    result_list = []
    # for future_obj in cf.as_completed(results):
    #     result_list.append(future_obj.result())

    for result in results:
        result_list.append(result)

    print( time.time() - T )
    print( np.average( result_list ) )
    print( len(result_list) )