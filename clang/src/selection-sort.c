#include <stdio.h>
#include <string.h>

#include "../headers/Arrays.h"
#include "../headers/Time.h"

int * _selection_sort(int * arr, int size)
{
    // Copy shuffled array to be mutated by sorting process
    int * src = malloc(sizeof(int) * size);
    memcpy(src, arr, sizeof(int) * size);
    // Result array to acomodate the min value removed from src on each iteration
    int * res = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        int min_val = src[0];
        int min_pos = 0;
        int j = 0;
        // Artificially reduces src array for each iteration combined with shift left
        const int src_size = size - i;
        while (j < src_size) {
            if (src[j] < min_val) {
                min_val = src[j];
                min_pos = j;
            }
            j++;
        }
        res[i] = min_val;
        // Shift left elems from pos..elem_count - 1
        for (int k = min_pos; k < src_size; k++) {
            src[k] = src[k + 1];
        }
    }
    free(src);
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
    printf("1. Time to generate array of size %d: %.0f ms\n", size, genResult.time);
    if (! is_sorted_as_expected(sortResult.arr, expected, size)) {
        printf("2. The result array is NOT sorted as expected\n");
    } else {
        printf("2. The result array is sorted as expected\n");
        printf("3. Time to selection sort the array: %.0f ms\n", sortResult.time);
    }

    free(genResult.arr);
    free(sortResult.arr);
    free(expected);
    return 0;
}
