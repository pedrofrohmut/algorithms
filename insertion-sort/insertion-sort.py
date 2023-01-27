#! /usr/bin/env python

from math import floor
from random import random
import numpy as np
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


def insertion_sort(arr):
    res = array("I", [])
    res.append(arr[0])
    for i in range(1, len(arr)):
        elem = arr[i]      # This variable exists for performance
        j = 0
        while j < i and res[j] < elem:
            j += 1
        res.insert(j, elem)
    return res


def main():
    size = 30_000
    arr = generate_array(size) # Source Array (Scrambled)

    start = time()
    res = insertion_sort(arr) # Result Array
    end = time()

    expected = array("I", [])
    for i in range(1, size):
        expected.append(i)

    if (np.array_equal(res, expected)):
        print("Result arrays is NOT as expected")
    else:
        print("Result arrays is as expected")
        total = floor((end - start) * 1000)
        print(f"Sorted in {total} milliseconds")

main()
