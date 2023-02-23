#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/Arrays.h"
#include "../headers/Time.h"

int * bubble_sort(int * arr, const int size)
{
    // size -1 ? 1 elem arr is already sorted
    for (int i = 0; i < size - 1; i++) {
        // Optimization(25ms): breaks out when no swap is made. That means the array is
        // already sorted
        bool has_swaped = false;
        // size - i - 1 ? that indicates the size of the unsorted part that grows
        // by one in each iteration.
        // -1 because you compare j with j + 1 and without -1 you overflow comparison
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Optimization(3323ms): Swap by reference makes it faster for some reason
                swap(&arr[j], &arr[j + 1]);
                has_swaped = true;
            }
        }
        if (! has_swaped) break;
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
