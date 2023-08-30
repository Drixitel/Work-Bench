import time
import concurrent.futures 
from mod import fib_C 


start = time.perf_counter()

# def fib_C(n):
#     if n <= 1:
#         return n
#     else:
#         return fib_C(n - 2) + fib_C(n - 1)

with concurrent.futures.ProcessPoolExecutor() as executor:

    list_of_results = executor.map(fib_C, range(32))

    # for result in list_of_results:
    #     # to handle exceptions it should be placed here 
    #     print(result)



finish = time.perf_counter()

print(f'Finished in {round(finish-start,2)} seconds(s)')