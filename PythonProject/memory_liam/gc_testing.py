import gc

print("Generational Thresholds: ", gc.get_threshold())
print("\t700 = 1st gen, 10 = 2nd gen, 10 = 3rd gen")

print("Initial GC count at startup: ", gc.get_count())
print("\tThese are the generational counts for all 3 generations.")

gc.collect()

print("GC count after forced collection: ", gc.get_count())

"""
 gc.get_count() = ( Threshold count , __ , __ )
    - To keep python running reasonably fast the gc doesn't and can't
      run all the time    
    - vast majority of the time it has nothing to do 
    - each time the GC is run nothing else can run (blocking)
        - this is one of the large reason for objections 
    - does not run on timer
    - runs on thresholds of generations 
"""

x = [1, 2, 3, 4]
y = [5, 6, 7, 8]
x.append(y)
y.append(x)



print("\nCyclical List objects: ", x, y)


print("\nGC count after object creation: ", gc.get_count())

del x  # deleting the reference not the object

print("GC count after deleting x: ", gc.get_count())

gc.collect()

print("GC count after forced collection: ", gc.get_count())

del y

print("GC count after deleting y: ", gc.get_count())


gc.collect()

print("GC count after forced collection: ", gc.get_count())
