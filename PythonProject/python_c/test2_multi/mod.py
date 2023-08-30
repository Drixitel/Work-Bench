import time

def do_something(seconds: int) -> str: 
    print(f'Sleeping {seconds} second...')
    time.sleep(seconds)
    return f'Done Sleeping...{seconds}' 

def fib_C(n: int) -> int:
    if n <= 1:
        return n
    else:
        return fib_C(n - 2) + fib_C(n - 1)