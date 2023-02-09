from math import floor
from time import time
from array import array

from arrays import (generate_shuffled_array,
                    is_sorted_as_expected,
                    generate_expected_array,
                    copy_array)
from time_utils import get_time_ms

def __selection_sort(src):
    res = array("I", [])
    for i in range(len(src)):
        min_val = src[0]
        min_pos = 0
        j = 0
        # Iterate the src to find new min_val
        while j < len(src):
            if src[j] < min_val:
                min_val = src[j]
                min_pos = j
            j += 1
        res.append(min_val)
        # Remove the min_val so the next can be found
        del src[min_pos]
    return res

def selection_sort(arr):
    copy = copy_array(arr)
    start = time()
    res = __selection_sort(copy)
    end = time()
    sort_time = get_time_ms(start, end)
    return res, sort_time


def main():
    size = 10000

    # Generate shuffled array
    arr, gen_time = generate_shuffled_array(size)

    # Sort shuffled array
    res, sort_time = selection_sort(arr)

    # Eval sorted array with an expected result
    expected = generate_expected_array(size)

    # Output the results
    print(f"1. Time to generate shuffled array of size {size}: {gen_time} ms")
    if not is_sorted_as_expected:
        print("2. The result array is NOT sorted as expected")
    else:
        print("2. The result array is sorted as expected")
        print(f"3. Time to selection sort the shuffled array: {sort_time} ms")


main()
