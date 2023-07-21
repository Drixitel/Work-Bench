import time

""" Type annotation only at input and output """

# Vanilla Python Code

# def fib_vanilla(n):
#     if n <= 1:
#         return n
#     else:
#         return fib_vanilla(n - 2) + fib_vanilla(n - 1)


# Type annotated Python code for mypyc


def fib_C(n: int) -> int:
    if n <= 1:
        return n
    else:
        return fib_C(n - 2) + fib_C(n - 1)


# will not compile & run correctly if the following is added:
# if __name__ == '__main__':

t0 = time.perf_counter()
# fib_vanilla(32)
fib_C(32)
print(time.perf_counter() - t0)
