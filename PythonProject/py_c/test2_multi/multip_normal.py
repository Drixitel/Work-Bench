import multiprocessing  # not needed for POOL EXECUTOR 
import time

# .join is automatic/implicit in concurrent.futures module 

start = time.perf_counter()


################################################################
#   FIRST VERSION OF MULTIPROCESSING (2 PROCESSES)
#       (risky to do it yourself--see concurrent.futures below )

# # function
# def do_something(): 
#     print('Sleeping 1 second...')
#     time.sleep(1)
#     print('Done Sleeping...')  

# # Turn these function calls into processes ------------
# do_something()
# do_something()
# # ------------------------------------------------------

# # Processes:  Pass the function not return value
# process_1 = multiprocessing.Process(target=do_something) 
# process_2 = multiprocessing.Process(target=do_something) 

# # Start the processes using .start() ---------------------------------
# #   Using .start() will not give you control of the order 
# #   it will jump to the next lines of code and execute them if the processes 
# #   are still running; this will cause issues if future code depends on previous 
# process_1.start()
# process_2.start() 

# # we need to tell the computer to wait until the process finishes before moving on
# process_1.join()
# process_2.join() 

# #---------------------------------------------------------

################################################################
#  CONVERT ABOVE CODE TO LOOP VERSION : NO ARGUMENTS 
#       (risky to do it yourself--see concurrent.futures below)

# # function
# def do_something(): 
#     print('Sleeping 1 second...')
#     time.sleep(1)
#     print('Done Sleeping...')  

# # create list to hold all the processes 
# processes = []

# # Run the function 10 times = create 10 processes
# #   Start the process after creating 
# #   save them to a list to use/loop over later 
# for _ in range(10): 
#     p = multiprocessing.Process(target=do_something) 
#     p.start()
#     # .join() here would cause the multiprocessor to wait until 
#     #   each process finishes before creating the next process 
#     # p.join()
#     processes.append(p)

# # Once all the processes are created we can call .join()
# #   this cannot be in the previous loop 
# for process in processes: 
#     process.join()

################################################################
# lOOP WITH ARGUMENTS 
#       (risky to do it yourself--see concurrent.futures below)

# # function
# def do_something(seconds): 
#     print(f'Sleeping {seconds} second...')
#     time.sleep(seconds)
#     print('Done Sleeping...')  


# processes = []

# for _ in range(10): 
#     p = multiprocessing.Process(target=do_something, args=[1]) 
#     # - arguments need to be capable of being serialized using pickle 
#     #   serialize with pickle: converting python obj into a format that can be 
#     #   deconstructed and reconstructed in another script 
#     p.start()
#     processes.append(p)

# for process in processes: 
#     process.join()

################################################################    
# lOOP WITH ARGUMENTS ; using Pool 
#       (risky to do it yourself--see concurrent.futures below)

# from multiprocessing import Pool, cpu_count
# from math import ceil

# # function
# def do_something(seconds): 
#     print(f'Sleeping {seconds} second...')
#     time.sleep(seconds)
#     return f'Done Sleeping... {seconds}'


# with Pool(processes=cpu_count()-1) as pool:
#     # each process is an interpreter so we want to keep one free to catch up others
#     # seconds_list = [5, 4, 3, 2, 1]
#     sec = [1,1,1,1,1,1,1,1,1,1]
    
#     # iter_of_results = pool.imap_unordered(do_something,seconds_list)
#     iter_of_results = pool.imap_unordered(do_something,range(10)) #.imap/ .imap_unordered 
#     #   .map waits until all results are ready b4 returning 

#     for result in iter_of_results: 
#         print(result)

    #testing: 
    # n_tasks = 10
    # n_tasks_per_chunk = ceil(n_tasks/len(pool._pool))
    # print(f'chunksize={n_tasks_per_chunk}, n_processes={len(pool._pool)}')
    # for result in pool.map(do_something, range(10), chunksize=1):
    #     print(result)

################################################################    
# USING PROCESS POOL EXECUTOR NOT WITH A LOOP 
#   safer to let the computer/this module to allot the processes to the cores then yourself

# import concurrent.futures 

# # function
# def do_something(seconds): 
#     print(f'Sleeping {seconds} second...')
#     time.sleep(seconds)
#     return 'Done Sleeping...' # return the string

# # Using the executor: this runs once 
# with concurrent.futures.ProcessPoolExecutor() as executor:
#     # .submit(function, argument) 
#     #   schedules a function to be executed and returns a future obj 
#     # future obj 
#     #   encapsulates the execution of our function and allows us to check on it 
#     #   while it is running (is it running what is the result )
#     future_object_1 = executor.submit(do_something, 1)
#     # .result()
#     #     grab the return value from the future object to print it 
#     print(future_object_1.result())

################################################################
# USING PROCESS POOL EXECUTOR (2 processes)
#   safer to let the computer/this module to allot the processes to the cores then yourself

# import concurrent.futures 

# # function
# def do_something(seconds): 
#     print(f'Sleeping {seconds} second...')
#     time.sleep(seconds)
#     return 'Done Sleeping...' 


# with concurrent.futures.ProcessPoolExecutor() as executor:
#     future_object_1 = executor.submit(do_something, 1)
#     future_object_2 = executor.submit(do_something, 1)
#     print(future_object_1.result()) #print the result of the function
#     print(future_object_2.result()) #print the result of the function

################################################################
# USING PROCESS POOL EXECUTOR (USING A POOL!!)
#   safer to let the computer/this module to allot the processes to the cores then yourself

# import concurrent.futures 

# # function
# def do_something(seconds): 
#     print(f'Sleeping {seconds} second...')
#     time.sleep(seconds)
#     return 'Done Sleeping...' 

# # create processes with executor 
# with concurrent.futures.ProcessPoolExecutor() as executor:
#     # list comprehension 
#     list_of_future_objects = [executor.submit(do_something, 1) for _ in range(10)]
#     # call attributes with concurrent.futures function 
#     #   as_completed : gives an iterator that yields .result as the processes are completed 

#     for future_obj in concurrent.futures.as_completed(list_of_future_objects):
#         # ^special iterator that works with the processes as they complete 
#         print(future_obj.result())

################################################################
# USING PROCESS POOL EXECUTOR (USING A POOL & multiple arguments)
#   safer to let the computer/this module to allot the processes to the cores then yourself
#  - This prints in the order the process was completed 
# import concurrent.futures 

# # function
# def do_something(seconds): 
#     print(f'Sleeping {seconds} second...')
#     time.sleep(seconds)
#     return f'Done Sleeping...{seconds}' 

# with concurrent.futures.ProcessPoolExecutor() as executor:
#     # arguments 
#     seconds_list = [9, 8, 7, 6, 5, 4, 3, 2, 1] # can see the core hang up 
#     # loop the list 
#     list_of_future_objects = [executor.submit(do_something, sec) for sec in seconds_list]
    
#     for future_obj in concurrent.futures.as_completed(list_of_future_objects):
#         print(future_obj.result())

################################################################
# USING PROCESS POOL EXECUTOR (USING A POOL & multiple arguments)
#   safer to let the computer/this module to allot the processes to the cores then yourself
#  - This prints in the order the process was given 
#  - shorter way to execute using map 
#  - is better 
# https://superfastpython.com/multiprocessing-pool-map-chunksize/

import concurrent.futures 
# from mod import do_something 
# function
def do_something(seconds): 
    print(f'Sleeping {seconds} second...')
    time.sleep(seconds)
    return f'Done Sleeping...{seconds}' 

with concurrent.futures.ProcessPoolExecutor() as executor:
    # arguments 
    # seconds_list = [5, 4, 3, 2, 1] 
    # loop the list with the process executor (using our function for the process)
    # .map
    #   does not return future objects; it only returns the results/ return statements
    #   - returns results in the order they were given 
    list_of_results = executor.map(do_something, range(10))

    for result in list_of_results:
        # to handle exceptions it should be placed here 
        print(result)


################################################################


finish = time.perf_counter()

print(f'Finished in {round(finish-start,2)} seconds(s)')