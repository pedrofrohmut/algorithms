#include <stdio.h>
#include <string.h>

#include "../headers/Arrays.h"
#include "../headers/Time.h"

int * insertion_sort(int * arr, int size)
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

int main()
{
    const int size = 30000;

    // Generate array
    const clock_t gen_start = clock();
    int * arr = generate_shuffled_array(size);
    const clock_t gen_end = clock();


    // Sort array
    const clock_t sort_start = clock();
    int * sorted = insertion_sort(arr, size);
    const clock_t sort_end = clock();

    // Eval sorted array with an expected result
    int * expected = generate_expected_array(size);

    // Print arrays if needed
    /* print_array(arr, size, "Arr"); */
    /* print_array(sorted, size, "Sorted"); */
    /* print_array(expected, size, "Expected"); */

    // Output the results
    printf("1. Time to generate array: %.4f ms\n", get_time_ms(gen_start, gen_end));
    if (! is_sorted_as_expected(sorted, expected, size)) {
        printf("2. The result array is NOT sorted as expected\n");
    } else {
        printf("2. The result array is sorted as expected\n");
        printf("3. Time to sort the array: %.4f ms\n", get_time_ms(sort_start, sort_end));
    }

    free(arr);
    free(sorted);
    free(expected);
    return 0;
}
