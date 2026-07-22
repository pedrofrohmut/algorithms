#include <stdio.h>
#include <stdlib.h>

#include "../headers/Arrays.h"
#include "../headers/Time.h"

int * _merge(int * left, int * right, int left_size, int right_size)
{
    int * merged = malloc(sizeof(int) * (left_size + right_size));

    // Optimization (14%)
    if (left_size == 1 && right_size == 1) {
        if (left[0] < right[0]) {
            merged[0] = left[0];
            merged[1] = right[0];
            return merged;
        } else {
            merged[0] = right[0];
            merged[1] = left[0];
            return merged;
        }
    }

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

    // Otimization: Escape for 2 sizeds (25% better performance)
    if (size == 2) {
        if (arr[0] < arr[1]) {
            return arr;
        } else {
            swap(&arr[0], &arr[1]);
            return arr;
        }
    }

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
    return (Result ) { sorted, get_time_ms(start, end) };
}

int main()
{
    const int size = 40000;

    // Generate array
    int * arr = generate_random_values_array(size);

    // Sort shuffled array
    Result sortResult = merge_sort(arr, size);

    // Output the results
    if (! is_sorted(sortResult.arr, size)) {
        printf("1. The result array is NOT sorted as expected\n");
    } else {
        printf("1. The result array is sorted as expected\n");
        printf("2. Time to merge sort the array: %.0f ms\n", sortResult.time);
    }

    free(arr);
    free(sortResult.arr);

    return 0;
}
