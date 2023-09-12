def f(x):
    return x*x

def simulate( x:int , p:float ) -> int :

    import random

    # We desire to grab x number of successes,
    # with each success having a p% chance.

    # we return r , the total number of trials.

    s = 0
    r = 0

    while ( s < x ) :

        if ( random.random() < p ) :

            s = s + 1

        r = r + 1

    return r

def run_simulation( nums:list ) -> int :

    return simulate(*nums)