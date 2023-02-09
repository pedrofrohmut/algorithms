from math import floor
from time import time
from array import array

from arrays import (generate_shuffled_array,
                    is_sorted_as_expected,
                    generate_expected_array,
                    copy_array)
from time_utils import get_time_ms

def __bubble_sort(arr):
    for i in range(0, len(arr)):
        for j in range(len(arr) - 1, i, -1):
            if arr[j] < arr[j - 1]:
                # Swap
                arr[j], arr[j- 1] = arr[j - 1], arr[j]
    return arr

def bubble_sort(arr):
    copy = copy_array(arr)
    start = time()
    res = __bubble_sort(copy)
    end = time()
    sort_time = get_time_ms(start, end)
    return res, sort_time


def main():
    size = 40000

    # Generate shuffled array
    arr, gen_time = generate_shuffled_array(size)

    # Sort shuffled array
    res, sort_time = bubble_sort(arr)

    # Eval sorted array with an expected result
    expected = generate_expected_array(size)

    # Output the results
    print(f"1. Time to generate shuffled array of size {size}: {gen_time} ms")
    if not is_sorted_as_expected:
        print("2. The result array is NOT sorted as expected")
    else:
        print("2. The result array is sorted as expected")
        print(f"3. Time to bubble sort the shuffled array: {sort_time} ms")


main()
