#include <stdio.h>
#include <string.h>

#include "../headers/Arrays.h"
#include "../headers/Time.h"

int * swap_selection_sort(int arr[], const int size)
{
    for (int i = 0; i < size - 1; i++) {
        int min_pos = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_pos]) min_pos = j;
        }
        if (i != min_pos) swap(&arr[i], &arr[min_pos]);
    }
    return arr;
}

Result bench_swap_selection_sort(const int arr[], const int size)
{
    int * arr_cpy = copy_array(arr, size);
    const clock_t start = clock();
    int * sorted = swap_selection_sort(arr_cpy, size);
    const clock_t end = clock();
    return (Result) { sorted, get_time_ms(start, end) };
}

int main()
{
    const int size = 40000;

    // Generate array
    int * arr = generate_random_values_array(size);

    // Sort shuffled array
    Result srt_res = bench_swap_selection_sort(arr, size);

    // Output the results
    if (! is_sorted(srt_res.arr, size)) {
        printf("1. The result array is NOT sorted as expected\n");
    } else {
        printf("1. The result array is sorted as expected\n");
        printf("2. Time to swap selection sort the array: %.0f ms\n", srt_res.time);
    }

    free(arr);
    free(srt_res.arr);

    return 0;
}
