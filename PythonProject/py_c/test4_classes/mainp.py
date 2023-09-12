# from mod import *
from time import perf_counter_ns
import time
from mod2 import *

def main() -> None:
    bag_instance = Bag()

    # Add elements to the bag
    bag_instance.add(5)
    bag_instance.add("Hello")
    bag_instance.add([1, 2, 3])

    # Add an element twice
    bag_instance.addtwice(10)

    # Print the contents of the bag
    print("Bag data:", bag_instance.data)
    print("Value of x:", bag_instance.x)


# def testfunc(*arg, sim = myClass): 
#     myClass = myClass()
#     # print("Bag data:", sim.data)
#     print(arg[0])

def main2(tempThing, *args, **kwargs):
    print(args)
    print(kwargs)
    print("Bag data:", tempThing.data)
    tempThing.add(6)
    print("Bag data:", tempThing.data)

if __name__ == "__main__": 
    # start = perf_counter_ns()

    # main()
    # testfunc(10)
    # print("Value of x....:", bag_instance.x) not global

    # end = perf_counter_ns() - start
    # print(end)
    bag = Bag()
    bag.add(5)
    main2(bag, "more test", namedtest="named-test")
    print("Bag data outside:", bag.data)