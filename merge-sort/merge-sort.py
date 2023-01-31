#! /usr/bin/env python

from random import random
from math import floor
from time import time
from array import array

def get_index(i):
    return floor(random() * i)


def generate_array(size):
    arr = array("I", [])
    for i in range(1, size + 1):
        index = get_index(i)
        arr.insert(index, i)
    return arr


def get_left_and_right(arr):
    extra = 0 if len(arr) % 2 == 0 else 1
    mid = floor(len(arr) / 2)
    left = arr[0:mid + extra]
    right = arr[mid + extra:]
    return left, right


def order_array(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while (j >= 0 and arr[j] > key):
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr


def merge_left_and_right(Left, Right):
    res_len = len(Left) + len(Right)
    res = array("I", [])
    left_index = 0
    right_index = 0
    for i in range(0, res_len):
        if right_index >= len(Right):
            res = res + Left[left_index:]
            break
        if left_index >= len(Left):
            res = res + Right[right_index:]
            break
        if Left[left_index] < Right[right_index]:
            res.append(Left[left_index])
            left_index += 1
        else:
            res.append(Right[right_index])
            right_index += 1
    return res


def compare_arrays(subject, expected):
    for i in range(0, len(subject)):
        if subject[i] != expected[i]:
            return False
    return True


def main():
    size = 30000

    # Generate array
    gen_start = time()
    arr = generate_array(size)
    gen_end = time()

    sort_start = time()

    # Get Left and Right
    left, right = get_left_and_right(arr)

    # Sort Left and Right (insertion sort)
    left = order_array(left)
    right = order_array(right)

    # Merge Left and Right
    merged = merge_left_and_right(left, right)

    sort_end = time()

    # Eval sorted array with an expected result
    expected = array("I", [])
    for i in range(1, size + 1):
        expected.append(i)
    are_equal = compare_arrays(merged, expected)

    # Output the results
    print(f"1. Time to generate array: {floor((gen_end - gen_start) * 1000)} ms")
    if not are_equal:
        print("2. Result array is NOT sorted as expected")
    else:
        print("2. Result array is sorted as expected")
        print(f"3. Time to merge sort the array: {floor((sort_end - sort_start) * 1000)} ms")

main()
