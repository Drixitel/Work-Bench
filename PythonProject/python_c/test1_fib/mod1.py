import numpy as np


def pi() -> float:
    return np.pi


def fib_C(n: int) -> int:
    if n <= 1:
        return n
    else:
        return fib_C(n - 2) + fib_C(n - 1)
