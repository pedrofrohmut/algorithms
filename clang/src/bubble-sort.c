#include <stdio.h>
#include <string.h>
#include <time.h>

#include "../headers/Arrays.h"
#include "../headers/Time.h"

int * bubble_sort(int * arr, int size)
{
    int * res = malloc(sizeof(int) * size);
    memcpy(res, arr, sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j > i; j--) {
            if (res[j] < res[j - 1]) {
                const int temp = res[j];
                res[j] = res[j - 1];
                res[j - 1] = temp;
            }
        }
    }

    return res;
}

int main()
{
    const int size = 30000;

    // Generate Array
    const clock_t gen_start = clock();
    int * arr = generate_shuffled_array(size);
    const clock_t gen_end = clock();

    // Sort array
    const clock_t sort_start = clock();
    int * res = bubble_sort(arr, size);
    const clock_t sort_end = clock();

    // Eval sorted array with an expected result
    int * expected = generate_expected_array(size);

    /* print_array(arr, size, "Arr"); */
    /* print_array(res, size, "Res"); */
    /* print_array(expected, size, "Expected"); */

    // Output the results
    printf("Time to generate the array: %.4f ms\n", get_time_ms(gen_start, gen_end));
    if (! is_sorted_as_expected(res, expected, size)) {
        printf("2. The result array is NOT sorted as expected\n");
    } else {
        printf("2. The result array is sorted as expected\n");
        printf("Time to bubble sort the array: %.4f ms\n", get_time_ms(sort_start, sort_end));
    }

    free(arr);
    free(res);
    free(expected);
    return 0;
}
