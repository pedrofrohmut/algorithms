#include <stdio.h>
#include <string.h>

#include "../headers/Arrays.h"
#include "../headers/Time.h"

int * selection_sort(int * arr, int size)
{
    // Copy shuffled array to be mutated by sorting process
    int * src = malloc(sizeof(int) * size);
    memcpy(src, arr, sizeof(int) * size);
    // Result array to acomodate the min value removed from src on each iteration
    int * res = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        int min_pos = 0;
        int j = 0;
        // Artificially reduces src array for each iteration combined with shift left
        const int src_size = size - i;
        while (j < src_size) {
            if (src[j] < src[min_pos]) min_pos = j;
            j++;
        }
        res[i] = src[min_pos];
        // Shift left elems from pos..elem_count - 1
        for (int k = min_pos; k < src_size; k++) {
            src[k] = src[k + 1];
        }
    }
    free(src);
    return res;
}

Result bench_selection_sort(int * arr, int size)
{
    const clock_t start = clock();
    int * sorted = selection_sort(arr, size);
    const clock_t end = clock();
    return (Result) { sorted, get_time_ms(start, end) };
}

int main()
{
    const int size = 40000;

    // Generate array
    int * arr = generate_random_values_array(size);

    // Sort shuffled array
    Result srt_res = bench_selection_sort(arr, size);

    // Output the results
    if (! is_sorted(srt_res.arr, size)) {
        printf("1. The result array is NOT sorted as expected\n");
    } else {
        printf("1. The result array is sorted as expected\n");
        printf("2. Time to selection sort the array: %.0f ms\n", srt_res.time);
    }

    free(arr);
    free(srt_res.arr);

    return 0;
}
