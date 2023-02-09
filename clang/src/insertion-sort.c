#include <stdio.h>
#include <string.h>

#include "../headers/Arrays.h"
#include "../headers/Time.h"

int * _insertion_sort(int * arr, int size)
{
    int * sorted = malloc(sizeof(int) * size);
    memcpy(sorted, arr, size * sizeof(int));
    for (int i = 1; i < size; i++) {
        int key = sorted[i];
        int j = i - 1;
        while (j >= 0 && sorted[j] > key) {
            sorted[j + 1] = sorted[j];
            j--;
        }
        sorted[j + 1] = key;
    }
    return sorted;
}

Result insertion_sort(int * arr, int size)
{
    const clock_t start = clock();
    int * sorted = _insertion_sort(arr, size);
    const clock_t end = clock();
    return (Result) { sorted, get_time_ms(start, end) };
}

int main()
{
    const int size = 40000;

    // Generate shuffled array
    Result genResult = generate_shuffled_array(size);

    // Sort shuffled array
    Result sortResult = insertion_sort(genResult.arr, size);

    // Eval sorted array with an expected result
    int * expected = generate_expected_array(size);

    // Output the results
    printf("1. Time to generate shuffled array of size %d: %.0f ms\n", size, genResult.time);
    if (! is_sorted_as_expected(sortResult.arr, expected, size)) {
        printf("2. The result array is NOT sorted as expected\n");
    } else {
        printf("2. The result array is sorted as expected\n");
        printf("3. Time to insertion sort the array: %.0f ms\n", sortResult.time);
    }

    free(genResult.arr);
    free(sortResult.arr);
    free(expected);
    return 0;
}
