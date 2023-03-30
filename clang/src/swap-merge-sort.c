#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../headers/Arrays.h"
#include "../headers/Time.h"

void merge(int arr[],
           const size_t left_begin,
           const size_t left_end,
           const size_t right_end);

void swap_merge_sort(int arr[], const size_t begin, const size_t end);

Result bench_sort_array(int arr[], const size_t size);

void test_and_output_results(const Result sortResult, const size_t size);


/*
   1. It already works as a regular merge sort but with memory allocation for the
   merge left and right chunks step

   2. Yet a did not find a way to merge left and right without memory allocation
   the tries are continue on paper and will be implemented once they are work

   3. The optimizations are secondary and will be added after the step is concluded
   */
int main()
{
    const size_t size = 40000;

    int * rnd_vals = generate_random_values_array(size);
    Result result = bench_sort_array(rnd_vals, size);
    test_and_output_results(result, size);

    // Dont need to free result.arr since it points to rnd_vals too
    free(rnd_vals);

    return 0;
}

void merge(int arr[],
           const size_t left_begin,
           const size_t left_end,
           const size_t right_end)
{
    int * merged = malloc(sizeof(int) * (right_end - left_begin + 1));

    size_t merged_index = 0;
    size_t left_index = left_begin;
    size_t right_index = left_end + 1;

    // Merge left and right until one of them reaches its end
    while (left_index <= left_end && right_index <= right_end) {
        if (arr[left_index] < arr[right_index]) {
            merged[merged_index] = arr[left_index];
            merged_index++;
            left_index++;
        } else {
            merged[merged_index] = arr[right_index];
            merged_index++;
            right_index++;
        }
    }

    // Append left remainders to merged
    while (left_index <= left_end) {
        merged[merged_index] = arr[left_index];
        merged_index++;
        left_index++;
    }

    // Append right remainders to merged
    while (right_index <= right_end) {
        merged[merged_index] = arr[right_index];
        merged_index++;
        right_index++;
    }

    // Write merged array into arg array
    merged_index = 0;
    for (size_t i = left_begin; i <= right_end; i++) {
        arr[i] = merged[merged_index];
        merged_index++;
    }

    free(merged);
}

void swap_merge_sort(int arr[], const size_t begin, const size_t end)
{
    if (begin == end) return;

    // left  => [begin        : left_end]
    // right => [left_end + 1 : end     ]
    size_t left_end = begin + floor(((double) end - begin) / 2);

    // Recursive call Left Chunk
    swap_merge_sort(arr, begin, left_end);

    // Recursive call Right Chunk
    swap_merge_sort(arr, left_end + 1, end);

    // Merge the chunks
    merge(arr, begin, left_end, end);
}

Result bench_sort_array(int arr[], const size_t size)
{
    clock_t start = clock();
    swap_merge_sort(arr, 0, size - 1);
    clock_t end = clock();
    double time = get_time_ms(start, end);
    return (Result) { arr, time };
}

void test_and_output_results(const Result sortResult, const size_t size)
{
    if (! is_sorted(sortResult.arr, size)) {
        printf("The result array is NOT sorted as expected\n");
    } else {
        printf("Time to swap merge sort the array with %zu elements: %.0f ms\n",
                size, sortResult.time);
    }
}
