#include <stdio.h>
#include <stdlib.h>

#include "../headers/Arrays.h"
#include "../headers/Time.h"

size_t partitioning(int arr[], const size_t begin, const size_t end)
{
    if (begin == end) return end;

    const size_t pivot_pos = end; // Pivot position: Right most element chunk
    size_t left_pos = begin;      // Left Position: Left most element
    size_t right_pos = end - 1;   // RightPosition: Last but one Right most

    do {
        // Advance left
        while (arr[left_pos] < arr[pivot_pos] && left_pos < pivot_pos) left_pos++;
        // Escape if all smaller than pivot
        if (left_pos == pivot_pos) return pivot_pos;
        // Advance Right
        while (arr[right_pos] > arr[pivot_pos] && right_pos > left_pos) right_pos--;
        // Swap everytime left and right stops
        swap(&arr[left_pos], &arr[right_pos]);
    } while (left_pos != right_pos);

    // The left and right points to same position.
    // Iteration is over swap left and pivot
    swap(&arr[left_pos], &arr[pivot_pos]);

    return left_pos;
}

void swap_quick_sort(int arr[], const size_t begin, const size_t end)
{
    const size_t res_pos = partitioning(arr, begin, end);

    // Recursive call on left chuck
    if (res_pos > begin + 1) {
        swap_quick_sort(arr, begin, res_pos - 1);
    }

    // Recursive call on right chuck
    if (res_pos < end - 1) {
        swap_quick_sort(arr, res_pos + 1, end);
    }
}

Benchmark_Result bench_swap_quick_sort(const size_t size)
{
    int * rnd_vals = generate_random_values_array(size);

    const clock_t start = clock();
    swap_quick_sort(rnd_vals, 0, size - 1);
    const clock_t end = clock();

    double time  = get_time_ms(start, end);
    bool sort_worked = is_sorted(rnd_vals, size);
    free(rnd_vals);
    return (Benchmark_Result) { time, sort_worked };
}

int main()
{
    const size_t bench_amt = 10;
    const size_t size = 40000;
    double avg_time = 0;

    for (size_t i = 0; i < bench_amt; i++) {
        Benchmark_Result res = bench_swap_quick_sort(size);
        if (! res.is_sorted) {
            printf("ERROR: The array is NOT sorted as expected\n");
            return 1;
        }
    }
    avg_time /= bench_amt;

    printf("BENCHMARK: The avarage time to insertion sort the %zu arrays is %0.f ms\n",
            bench_amt, avg_time);
    return 0;
}
