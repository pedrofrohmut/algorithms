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

Result bench_insertion_sort(int * arr, int size)
{
    const clock_t start = clock();
    int * sorted = insertion_sort(arr, size);
    const clock_t end = clock();
    return (Result) { sorted, get_time_ms(start, end) };
}

int main()
{
    const int size = 40000;

    // Generate shuffled array
    int * rnd_arr = generate_random_values_array(size);

    // Sort shuffled array
    Result sort_res = bench_insertion_sort(rnd_arr, size);

    // Output the results
    if (! is_sorted(sort_res.arr, size)) {
        printf("1. The result array is NOT sorted as expected\n");
    } else {
        printf("1. The result array is sorted as expected\n");
        printf("2. Time to insertion sort the array: %.0f ms\n", sort_res.time);
    }

    free(rnd_arr);
    free(sort_res.arr);

    return 0;
}
