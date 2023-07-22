import time

###########################################
# Type annotation only at input and output
###########################################


# Type annotated Python code for mypyc


def fib_C(n: int) -> int:
    if n <= 1:
        return n
    else:
        return fib_C(n - 2) + fib_C(n - 1)


# will not compile & run correctly if the following is added:
# if __name__ == '__main__':

# let this be the main then move fib to the other file

t0 = time.perf_counter()

fib_C(32)
# print(pi())

print(time.perf_counter() - t0)
