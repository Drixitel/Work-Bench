import time


###########################################
# Type annotation only at input and output
###########################################


# Vanilla Python Code


def fib_vanilla(n):
    if n <= 1:
        return n
    else:
        return fib_vanilla(n - 2) + fib_vanilla(n - 1)


# will not compile & run correctly if the following is added:
# if __name__ == '__main__':

# let this be the main then move fib to the other file

t0 = time.perf_counter()
fib_vanilla(32)

# print(pi())

print(time.perf_counter() - t0)
