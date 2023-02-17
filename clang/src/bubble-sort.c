#include <stdio.h>
#include <string.h>

#include "../headers/Arrays.h"
#include "../headers/Time.h"

int * bubble_sort(int * arr, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(&arr[j], &arr[j - 1]);
            }
        }
    }
    return arr;
}

Result bench_bubble_sort(int * arr, int size)
{
    int * arr_cpy = malloc(sizeof(int) * size);
    memcpy(arr_cpy, arr, sizeof(int) * size);
    const clock_t start = clock();
    int * result_array = bubble_sort(arr_cpy, size);
    const clock_t end = clock();
    return (Result) { result_array, get_time_ms(start, end) };
}

int main()
{
    const int size = 40000;

    // Generate Array
    int * arr = generate_random_values_array(size);

    // Sort array
    Result sort_res = bench_bubble_sort(arr, size);

    // Output the results
    if (! is_sorted(sort_res.arr, size)) {
        printf("1. The result array is NOT sorted as expected\n");
    } else {
        printf("1. The result array is sorted as expected\n");
        printf("2. Time to bubble sort the array: %.0f ms\n", sort_res.time);
    }

    free(arr);
    free(sort_res.arr);

    return 0;
}
