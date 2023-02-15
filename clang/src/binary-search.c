#include <stdio.h>

#include "../headers/Arrays.h"
#include "../headers/Time.h"

const int binary_search(const int arr[], int start, int end, const int value)
{
    while (end != start) {
        const int mid = ((end - start + 1) / 2) + start;
        if (arr[mid] == value) return mid;
        if (arr[mid] > value) { end = mid - 1; }
        if (arr[mid] < value) { start = mid + 1; }
    }
    if (arr[end] != value) {
        return -1;
    }
    return end;
}

Result bench_binary_search(const int ord_arr[], const int rnd_arr[], const int size)
{
    int * positions = malloc(sizeof(int) * size);
    const clock_t start = clock();
    for (int i = 0; i < size; i++) {
        const int value = rnd_arr[i];
        const int start = 0;
        const int end = size - 1;
        const int pos = binary_search(ord_arr, start, end, value);
        positions[i] = pos;
    }
    const clock_t end = clock();
    const double search_time = get_time_ms(start, end);
    return (Result) {positions, search_time};
}

int * generate_expected_positions_array(const int rnd_arr[], const int size)
{
    int * expected = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        expected[i] = rnd_arr[i] - 1;
    }
    return expected;
}

bool is_positions_as_expected(int positions[], int expected[], const int size)
{
    for (int i = 0; i < size; i++) {
        if (positions[i] != expected[i]) return false;
    }
    return true;
}

int main()
{
    const int size = 40000;

    // Generate Shuffled Array
    int * rnd_arr = generate_shuffled_array(size);
    int * ord_cpy = get_ordered_copy(rnd_arr, size);

    // Bench binary search all results
    Result sch_res = bench_binary_search(ord_cpy, rnd_arr, size);

    // Eval search results with expected positions
    int * expected = generate_expected_positions_array(rnd_arr, size);

    // Output the results
    if (! is_positions_as_expected(sch_res.arr, expected, size)) {
        printf("1. The positions are NOT as expected\n");
    } else {
        printf("1. The positions are as expected\n");
        printf("2. Time to binary search all the values in the ordered array of"
                " size %d: %.0f ms\n", size, sch_res.time);
    }

    free(rnd_arr);
    free(ord_cpy);
    free(sch_res.arr);
    free(expected);
    return 0;
}
