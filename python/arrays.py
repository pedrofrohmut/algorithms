from random import random
from array import array
from math import floor
from time import time

def generate_shuffled_array(size):
    start = time()
    arr = __generate_shuffled_array(size)
    end = time()
    gen_time = floor((end - start) * 1000)
    return arr, gen_time


def __generate_shuffled_array(size):
    arr = array("I", [])
    for i in range(1, size + 1):
        index = floor(random() * i)
        arr.insert(index, i)
    return arr


def generate_expected_array(size):
    expected = array("I", [])
    for x in range(1, size + 1):
        expected.append(x)
    return expected


def is_sorted_as_expected(subject, expected):
    for i in range(len(subject)):
        if subject[i] != expected[i]:
            return False
    return True


def print_array(arr, name):
    for i in range(0, len(arr)):
        print(f"{name} [{i}]  = {arr[i]}")


def copy_array(arr):
    copy = array("I", [])
    for x in arr:
        copy.append(x)
    return copy
