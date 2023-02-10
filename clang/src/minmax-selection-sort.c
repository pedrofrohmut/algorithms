#include <stdio.h>
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
        int minv = src[0];
        int maxv = src[0];
        // Positions
        int minp = 0;
        int maxp = 0;
        int j = 0;
        // Virtual size
        int src_size = size - i;
        // Find max and min value and position
        while (j < src_size) {
            if (src[j] < minv) { minv = src[j]; minp = j; }
            if (src[j] > maxv) { maxv = src[j]; maxp = j; }
            j++;
        }
        // Add mix and max to result array
        res[i / 2] = minv;
        res[(size - 1)  - (i / 2)] = maxv;
        // Get the position of first and second elements to be removed from left to right
        int firstp = 0;
        int secondp = 0;
        if (minp < maxp) {
            firstp = minp; secondp = maxp;
        } else {
            firstp = maxp; secondp = minp;
        }
        // Virtual remove min and max from src with shift left
        for (int k = firstp; k < secondp  - 1; k++) { // Remove first elem
            src[k] = src[k + 1];
        }
        for (int k = secondp - 1; k < src_size - 2; k++) { // Remove second elem
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
    Result genResult = generate_shuffled_array(size);

    // Sort shuffled array
    Result sortResult = minmax_selection_sort(genResult.arr, size);

    // Eval sorted array with an expected result
    int * expected = generate_expected_array(size);

    // Output the results
    printf("1. Time to generate array of size %d: %.0f ms\n", size, genResult.time);
    if (! is_sorted_as_expected(sortResult.arr, expected, size)) {
        printf("2. The result array is NOT sorted as expected\n");
    } else {
        printf("2. The result array is sorted as expected\n");
        printf("3. Time to minmax selection sort the array: %.0f ms\n", sortResult.time);
    }

    free(genResult.arr);
    free(sortResult.arr);
    free(expected);
    return 0;
}
