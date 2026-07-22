#include <stdio.h> // printf
#include <stdlib.h> // free
#include <time.h> // clock_t
#include <stdbool.h> // bool

#include "../headers/Arrays.h"
#include "../headers/Time.h"

int partitioning(int arr[], const size_t begin, const size_t end)
{
    if (begin == end) return end;

    const size_t pivot_pos = end;
    size_t left_pos = begin;
    size_t right_pos = end - 1;

    do {
        while (arr[left_pos] < arr[pivot_pos] && left_pos < pivot_pos) left_pos++;
        if (left_pos == pivot_pos) return left_pos;
        while (arr[right_pos] > arr[pivot_pos] && right_pos > left_pos) right_pos--;
        swap(&arr[left_pos], &arr[right_pos]);
    } while(left_pos != right_pos);

    swap(&arr[left_pos], &arr[pivot_pos]);

    return left_pos;
}

// Search Position == 0 means the smallest
// Search Position == size - 1 means the biggest
int quick_select(int arr[], const size_t begin, const size_t end, const size_t search_pos)
{
    const size_t res_pos = partitioning(arr, begin, end);

    if (res_pos == search_pos) return arr[res_pos];

    if (search_pos < res_pos) {
        // Search on Left chuck
        return quick_select(arr, begin, res_pos - 1, search_pos);
    } else {
        // Search on Right chuck
        return quick_select(arr, res_pos + 1, end, search_pos);
    }
}

typedef struct {
    size_t position;
    int  value;
    clock_t time; // raw clock value
} Search_Result;

typedef struct {
    double time;
    bool is_valid;
} Search_Benchmark;

double get_time_sum_ms(const Search_Result results[], const size_t size)
{
    clock_t time_acc = 0;
    for (size_t i = 0; i < size; i++) {
        time_acc += results[i].time;
    }
    return ((double) time_acc / CLOCKS_PER_SEC) * 1000;
}

bool is_positions_as_expected(const int sorted_arr[],
                              const Search_Result results[],
                              const size_t size)
{
    for (size_t i = 0; i < size; i++) {
        if (results[i].value != sorted_arr[results[i].position]) return false;
    }
    return true;
}

Search_Benchmark bench_quick_search(const int arr[], const size_t size)
{
    Search_Result * results = malloc(sizeof(Search_Result) * size);

    for (size_t i = 0; i < size; i++) {
        // Always copy because quick_select modifies the array and can impact other results
        int * arr_cpy = copy_array(arr, size);
        const clock_t start = clock();
        const int value = quick_select(arr_cpy, 0, size - 1, i);
        const clock_t end = clock();
        free(arr_cpy);
        results[i] = (Search_Result) { i, value, (end - start) };
    }

    const double total_time = get_time_sum_ms(results, size);
    int * sorted_cpy = get_ordered_copy(arr, size);
    const bool positions_right = is_positions_as_expected(sorted_cpy, results, size);
    free(results);
    free(sorted_cpy);
    return (Search_Benchmark) {total_time, positions_right};
}

int main()
{
    const size_t size = 40000;

    int * rnd_arr = generate_random_values_array(size);

    Search_Benchmark bench = bench_quick_search(rnd_arr, size);

    if (! bench.is_valid) {
        printf("1. Failed: The positions are NOT as expected\n");
    } else {
        printf("1. Success: The positions are as expected\n");
        printf("2. Time to quick select all the values in the random number array"
               "of size %zu: %.0f ms\n", size, bench.time);
    }

    free(rnd_arr);

    return 0;
}
