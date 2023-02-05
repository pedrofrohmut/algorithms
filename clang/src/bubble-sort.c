#include <stdio.h>
#include <time.h>

#include "../headers/Arrays.h"
#include "../headers/Time.h"

void bubble_sort(int * arr, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                const int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
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
    bubble_sort(arr, size);
    const clock_t sort_end = clock();

    // Eval sorted array with an expected result
    int * expected = generate_expected_array(size);

    // Output the results
    printf("Time to generate the array: %.4f ms\n", get_time_ms(gen_start, gen_end));
    if (! is_sorted_as_expected(arr, expected, size)) {
        printf("2. The result array is NOT sorted as expected\n");
    } else {
        printf("2. The result array is sorted as expected\n");
        printf("Time to bubble sort the array: %.4f ms\n", get_time_ms(sort_start, sort_end));
    }

    free(arr);
    free(expected);
    return 0;
}
