#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/Arrays.h"
#include "../headers/Time.h"

int * _merge(int * left, int * right, int left_size, int right_size)
{
    int * merged = malloc(sizeof(int) * (left_size + right_size));
    int left_index = 0;
    int right_index = 0;
    for (int i = 0; i < (left_size + right_size); i++) {
        // Break condition => concatenates the remainders to the end of merged array if any
        if (left_index >= left_size) {
            for (int i = right_index; i < right_size; i++) {
                merged[i + left_index] = right[i];
            }
            break;
        }

        // Break condition => concatenates the remainders to the end of merged array if any
        if (right_index >= right_size) {
            for (int i = left_index; i < left_size; i++) {
                merged[i + right_index] = left[i];
            }
            break;
        }

        // Normal sorting
        if (left[left_index] < right[right_index]) {
            merged[i] = left[left_index];
            left_index++;
        } else {
            merged[i] = right[right_index];
            right_index++;
        }
    }
    return merged;
}

int * _merge_sort(int * arr, int size)
{
    // Recursion escape condition
    if (size == 1) return arr;

    // Sizes
    const int extra = size % 2 == 0 ? 0 : 1;
    const int left_size = size / 2 + extra;
    const int right_size = size / 2;

    // Create left and right
    int * left = malloc(sizeof(int) * left_size);
    int * right = malloc(sizeof(int) * right_size);
    for (int i = 0; i < left_size; i++) {
        left[i] = arr[i];
    }
    for (int i = 0; i < right_size; i++) {
        right[i] = arr[left_size + i];
    }

    // Recursion
    int * merged_left = _merge_sort(left, left_size);
    int * merged_right = _merge_sort(right, right_size);

    // Merge when recursion reaches escape condition
    int * merged = _merge(merged_left, merged_right, left_size, right_size);

    // Clean up
    free(left);
    free(right);

    return merged;
}

Result merge_sort(int * arr, int size)
{
    const clock_t start = clock();
    int * sorted = _merge_sort(arr, size);
    const clock_t end = clock();
    Result res = { sorted, get_time_ms(start, end) };
    return res;
}

int main()
{
    const int size = 40000;

    // Generate array
    Result genResult = generate_shuffled_array(size);

    // Sort shuffled array
    Result sortResult = merge_sort(genResult.arr, size);

    // Eval sorted array with an expected result
    int * expected = generate_expected_array(size);

    // Output the results
    printf("1. Time to generate array of size %d: %.0f ms\n", size, genResult.time);
    if (! is_sorted_as_expected(sortResult.arr, expected, size)) {
        printf("2. The result array is NOT sorted as expected\n");
    } else {
        printf("2. The result array is sorted as expected\n");
        printf("3. Time to merge sort the array: %.0f ms\n", sortResult.time);
    }

    free(genResult.arr);
    free(sortResult.arr);
    free(expected);
    return 0;
}
