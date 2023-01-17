#! /usr/bin/env python

arr = [5, 19, 20, 2, 15, 17, 4, 6, 14, 7, 21, 1, 16, 9, 12, 13, 3, 18, 10, 8, 11]
res = []

if arr[0] < arr[1]:
    res.append(arr[0])
    res.append(arr[1])
else:
    res.append(arr[1])
    res.append(arr[0])

for i in range(2, len(arr)):
    j = 0
    while j < len(res) and res[j] < arr[i]:
        j += 1
    if j >= i:
        res.append(arr[i])
    else:
        res.insert(j, arr[i])

# print("\nArr -------------------------")
# for v, i in enumerate(arr):
#     print(f"v = {v}, i = {i}")
# print("\nRes -------------------------")
# for v, i in enumerate(res):
#     print(f"v = {v}, i = {i}")
