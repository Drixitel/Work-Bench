import numpy as np
import zlib
import gc
import time
import sys
from memory_profiler import profile


@profile
def compress_array(array):
    compressed = zlib.compress(array)
    return compressed


@profile
def decompress_array(compressed_array):
    decompressed = zlib.decompress(compressed_array)
    return decompressed


@profile
def main():
    # Create a large array of random integers
    array = np.random.randint(0, 100, size=(1000, 1000))

    # Print the size of the original array
    print("Original array size:", array.nbytes, "bytes")

    # Disable automatic garbage collection
    gc.disable()

    # Start measuring program speed
    start_time = time.time()

    # Compress the array
    compressed_array = compress_array(array)

    # Print the size of the compressed array
    print("Compressed array size:", len(compressed_array), "bytes")

    # Explicitly trigger garbage collection
    gc.collect()

    # Decompress the array
    decompressed_array = decompress_array(compressed_array)

    # Check if the decompressed array matches the original array
    print("Arrays are equal:", np.array_equal(array, decompressed_array))

    # Calculate program execution time
    execution_time = time.time() - start_time
    print("Program execution time:", execution_time, "seconds")

    # Calculate memory usage
    memory_usage = (
        sys.getsizeof(array)
        + sys.getsizeof(compressed_array)
        + sys.getsizeof(decompressed_array)
    )
    print("Total memory usage:", memory_usage, "bytes")

    # Re-enable automatic garbage collection
    gc.enable()


if __name__ == "__main__":
    main()
