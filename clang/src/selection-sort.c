#include <stdio.h>
#include <string.h>

#include "../headers/Arrays.h"
#include "../headers/Time.h"

int * _selection_sort(int * arr, int size)
{
    int * src = malloc(sizeof(int) * size);
    memcpy(src, arr, sizeof(int) * size);
    int * res = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        int min_val = src[0];
        int min_pos = 0;
        int j = 0;
        const int elem_count = size - i;
        while (j < elem_count) {
            if (src[j] < min_val) {
                min_val = src[j];
                min_pos = j;
            }
            j++;
        }
        res[i] = min_val;
        // Shift left elems from pos..elem_count - 1
        for (int k = min_pos; k < elem_count; k++) {
            src[k] = src[k + 1];
        }
    }
    return res;
}

Result selection_sort(int * arr, int size)
{
    const clock_t start = clock();
    int * sorted = _selection_sort(arr, size);
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
    Result sortResult = selection_sort(genResult.arr, size);

    // Eval sorted array with an expected result
    int * expected = generate_expected_array(size);

    // Output the results
    printf("1. Time to generate array of size %d: %.4f ms\n", size, genResult.time);
    if (! is_sorted_as_expected(sortResult.arr, expected, size)) {
        printf("2. The result array is NOT sorted as expected\n");
    } else {
        printf("2. The result array is sorted as expected\n");
        printf("3. Time to insertion sort the array: %.4f ms\n", sortResult.time);
    }

    free(genResult.arr);
    free(sortResult.arr);
    free(expected);
    return 0;
}
