from math import floor, ceil
from time import time
from array import array

from arrays import (generate_shuffled_array,
                    is_sorted_as_expected,
                    generate_expected_array,
                    copy_array, print_array)
from time_utils import get_time_ms


def __merge(left, right):
    res = array("I", [])
    l = 0
    r = 0
    # Merge sorted halves until one of indexes reach the length
    while l < len(left) and r < len(right):
        if left[l] < right[r]:
            res.append(left[l])
            l += 1
        else:
            res.append(right[r])
            r += 1
    # Append left remainders if any
    while l < len(left):
        res.append(left[l])
        l += 1
    # Append right remainders if any
    while r < len(right):
        res.append(right[r])
        r += 1
    return res


def __merge_sort(arr):
    if len(arr) <= 1: return arr
    # Split in two halves called left and right
    mid = ceil(len(arr) / 2)
    left = arr[0:mid]
    right = arr[mid:]
    # Recursive call to split until escape condition
    merged_left = __merge_sort(left)
    merged_right = __merge_sort(right)
    # Merge the two sorted halves
    merged = __merge(merged_left, merged_right)
    return merged


def merge_sort(arr):
    copy = copy_array(arr)
    start = time()
    res = __merge_sort(copy)
    end = time()
    sort_time = get_time_ms(start, end)
    return res, sort_time


def main():
    size = 40000

    # Generate shuffled array
    arr, gen_time = generate_shuffled_array(size)

    # Sort shuffled array
    res, sort_time = merge_sort(arr)

    # Eval sorted array with an expected result
    expected = generate_expected_array(size)

    # Output the results
    print(f"1. Time to generate shuffled array of size size: {gen_time} ms")
    if not is_sorted_as_expected:
        print("2. The result array is NOT sorted as expected")
    else:
        print("2. The result array is sorted as expected")
        print(f"3. Time to merge sort the shuffled array: {sort_time} ms")


main()
