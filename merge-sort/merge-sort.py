#! /usr/bin/env python

import math

def order_array(arr):
    res =  []
    res.append(arr[0])
    for i in range(1, len(arr)):
        j = 0
        while j < len(res) and res[j] < arr[i]:
            j += 1
        if j >= i:
            res.append(arr[i])
        else:
            res.insert(j, arr[i])
    return res

def get_left_and_right(arr):
    mid = math.floor(len(arr) / 2)
    Left = arr[0:mid]
    Right = arr[mid:]
    return Left, Right


def merge_left_and_right(Left, Right):
    res_len = len(Left) + len(Right)
    res = []
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


# arr is the full array with 40 elements
arr = [5, 30, 34, 19, 20, 31, 33, 2, 15, 32, 25, 17, 38, 4, 6, 23, 29, 40, 14, 7, 36, 21, 1, 16, 39, 26, 35, 9, 12, 13, 24, 3, 37, 18, 27, 10, 8, 28, 11, 22]

Left, Right = get_left_and_right(arr)

Left = order_array(Left)
Right = order_array(Right)

res = merge_left_and_right(Left, Right)

# for i, v in enumerate(res): print(f"res[{i}] = {v}")
