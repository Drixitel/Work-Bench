import time

from mod1 import pi, fib_C

###########################################
# Type annotation only at input and output
###########################################


# will not compile & run correctly if the following is added:
if __name__ == "__main__":
    # let this be the main then move fib to the other file

    t0 = time.perf_counter()
    # fib_vanilla(32)

    fib_C(32)
    print(pi())

    print(time.perf_counter() - t0)
