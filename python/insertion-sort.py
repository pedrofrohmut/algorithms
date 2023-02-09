from math import floor
from time import time
from array import array

from arrays import (generate_shuffled_array,
                    is_sorted_as_expected,
                    generate_expected_array,
                    copy_array)
from time_utils import get_time_ms

def __insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i
        while j > 0 and arr[j - 1] > key:
            arr[j] = arr[j - 1]
            j -= 1
        arr[j] = key
    return arr


def insertion_sort(arr):
    copy = copy_array(arr)
    start = time()
    res = __insertion_sort(copy)
    end = time()
    sort_time = get_time_ms(start, end)
    return res, sort_time


def main():
    size = 40000

    # Generate shuffled array
    arr, gen_time = generate_shuffled_array(size)

    # Sort shuffled array
    res, sort_time = insertion_sort(arr)

    # Eval sorted array with an expected result
    expected = generate_expected_array(size)

    # Output the results
    print(f"1. Time to generate shuffled array of size {size}: {gen_time} ms")
    if not is_sorted_as_expected:
        print("2. The result array is NOT sorted as expected")
    else:
        print("2. The result array is sorted as expected")
        print(f"3. Time to insertion sort the shuffled array: {sort_time} ms")


main()
