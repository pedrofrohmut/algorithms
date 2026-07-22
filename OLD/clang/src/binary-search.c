#include <stdio.h>
#include <stdlib.h>

#include "../headers/Arrays.h"
#include "../headers/Time.h"

typedef struct { int index; int value; } Position_Pairs;
typedef struct { Position_Pairs * arr; double time; } Search_Result;

const int binary_search(const int arr[], int start, int end, const int value)
{
    while (end != start) {
        const int mid = ((end - start + 1) / 2) + start;
        if (arr[mid] == value) return mid;
        if (arr[mid] > value) { end = mid - 1; }
        if (arr[mid] < value) { start = mid + 1; }
    }
    if (arr[end] != value) return -1;
    return end;
}

const int recursion_binary_search(const int arr[], const int start, const int end, const int value)
{
    if (start != end) {
        const int mid = ((end - start + 1) / 2) + start;
        if (arr[mid] == value) return mid;
        if (arr[mid] > value) {
            return recursion_binary_search(arr, start, mid - 1, value);
        }
        if (arr[mid] < value) {
            return recursion_binary_search(arr, mid + 1, end, value);
        }
    }
    if (arr[end] != value) return -1;
    return end;
}

Search_Result bench_binary_search(const int ord_arr[], const int rnd_arr[], const int size)
{
    Position_Pairs * positions = malloc(sizeof(Position_Pairs) * size);
    const clock_t start = clock();
    for (int i = 0; i < size; i++) {
        const int value = rnd_arr[i];
        const int start = 0;
        const int end = size - 1;
        const int pos = recursion_binary_search(ord_arr, start, end, value);
        positions[i] = (Position_Pairs) { pos, value };
    }
    const clock_t end = clock();
    const double search_time = get_time_ms(start, end);
    return (Search_Result) {positions, search_time};
}

bool is_positions_as_expected(Position_Pairs pairs[], int ordered[], const int size)
{
    for (int i = 0; i < size; i++) {
        if (pairs[i].value != ordered[pairs[i].index]) return false;
    }
    return true;
}

int main()
{
    const int size = 40000;

    // Generate Shuffled Array
    int * rnd_arr = generate_random_values_array(size);
    int * ord_cpy = get_ordered_copy(rnd_arr, size);

    // Bench binary search all results
    Search_Result sch_res = bench_binary_search(ord_cpy, rnd_arr, size);

    // Output the results
    if (! is_positions_as_expected(sch_res.arr, ord_cpy, size)) {
        printf("1. The positions are NOT as expected\n");
    } else {
        printf("1. The positions are as expected\n");
        printf("2. Time to binary search all the values in the ordered array of"
                " size %d: %.0f ms\n", size, sch_res.time);
    }

    free(rnd_arr);
    free(ord_cpy);
    free(sch_res.arr);

    return 0;
}
