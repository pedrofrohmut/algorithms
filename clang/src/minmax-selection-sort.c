#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/Arrays.h"
#include "../headers/Time.h"

int * _minmax_selection_sort(int * arr, int size)
{
    // Copy shuffled array to be mutated by sorting process
    int * src = malloc(sizeof(int) * size);
    memcpy(src, arr, sizeof(int) * size);
    // Result array to acomodate the min value removed from src on each iteration
    int * res = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i += 2) { // step 2 because it takes 2 elems by iteration
        // Values
        int min_val = src[0];
        int max_val = src[0];
        // Positions
        int min_pos = 0;
        int max_pos = 0;
        int j = 0;
        // Virtual size
        const int src_size = size - i;
        // Find max and min value and position
        while (j < src_size) {
            if (src[j] < min_val) { min_val = src[j]; min_pos = j; }
            if (src[j] > max_val) { max_val = src[j]; max_pos = j; }
            j++;
        }
        // Add min and max to result array
        res[i / 2] = min_val;
        res[(size - 1)  - (i / 2)] = max_val;
        // Get the position of first and second elements to be removed from left to right
        int first_pos = 0;
        int second_pos = 0;
        if (min_pos < max_pos) {
            first_pos = min_pos; second_pos = max_pos;
        } else {
            first_pos = max_pos; second_pos = min_pos;
        }
        // Virtual remove min and max from src with shift left
        // 1. Remove First Elem: [First : Second - 2] => src[i] = src[i + 1]
        for (int k = first_pos; k < second_pos  - 1; k++) {
            src[k] = src[k + 1];
        }
        // 2. Remove Second Elem: [Second - 1 : SrcSize - 2] => src[i] = src[i + 2]
        for (int k = second_pos - 1; k < src_size - 2; k++) {
            src[k] = src[k + 2];
        }
    }
    free(src);
    return res;
}

Result minmax_selection_sort(int * arr, int size)
{
    const clock_t start = clock();
    int * sorted = _minmax_selection_sort(arr, size);
    const clock_t end = clock();
    return (Result) { sorted, get_time_ms(start, end) };
}

int main()
{
    const int size = 40000;

    // Generate array
    int * arr = generate_random_values_array(size);

    // Sort shuffled array
    Result sortResult = minmax_selection_sort(arr, size);

    // Output the results
    if (! is_sorted(sortResult.arr, size)) {
        printf("1. The result array is NOT sorted as expected\n");
    } else {
        printf("1. The result array is sorted as expected\n");
        printf("2. Time to minmax selection sort the array: %.0f ms\n", sortResult.time);
    }

    free(arr);
    free(sortResult.arr);

    return 0;
}
