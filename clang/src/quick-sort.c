#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/Arrays.h"
#include "../headers/Time.h"

int counter = 0;

int partitioning(int * arr, const int size, const int begin, const int end)
{
    if (end - begin < 1) return begin;

    const int pivot_pos = end;     // left most element
    int left_pos        = begin;   // first position of the chunk ([begin:end])
    int right_pos       = end - 1; // last but one position of the current chunk

    while (left_pos < pivot_pos && left_pos != right_pos) {
        // Advance left checker
        while (arr[left_pos] < arr[pivot_pos] && left_pos < pivot_pos) {
            left_pos++;
        }

        // Means: every element is smaller the pivot. Nothing to do
        if (left_pos == pivot_pos) return pivot_pos;

        // Advance right checker
        while (arr[right_pos] > arr[pivot_pos] && right_pos > left_pos) {
            right_pos--;
        }

        if (left_pos < right_pos) { // Maybe unecesary if (testing)
            swap(&arr[left_pos], &arr[right_pos]);
        }
    }

    if (left_pos < pivot_pos && arr[left_pos] > arr[pivot_pos]) { // Maybe unecesary if (testing)
        swap(&arr[left_pos], &arr[pivot_pos]);
    }

    return left_pos;
}

void quick_sort(int * arr, const int size, const int begin, const int end)
{
    /* if (begin == end) return; */

    counter++;
    if (counter > 42) return;

    const int res_pos = partitioning(arr, size, begin, end);

    printf("\nCounter: %d, Pivot_Pos: %d, Begin: %d, End: %d\n", counter, res_pos, begin, end);
    print_array_inline(arr, size, "SORT    ");


    /* if (begin == res_pos) { printf("\nBEGIN == RES_POS\n"); } */

    if (res_pos - begin > 0) {
        quick_sort(arr, size, begin, res_pos - 1);
    }

    if (end - res_pos > 0) {
        quick_sort(arr, size, res_pos + 1, end);
    }
}

// Quick Sort no extra memory allocation
Result bench_quick_sort(int * arr, const int size)
{
    const clock_t start = clock();
    quick_sort(arr, size, 0, size - 1);
    const clock_t end = clock();
    return (Result) { arr, get_time_ms(start, end) };
}

void test_arr()
{
    int arr[] = {10, 1, 9, 5, 11, 12};
    const int size = sizeof(arr) / sizeof(int);
    int res = 666;

    printf("\nOriginal\n");
    print_array_inline(arr, size, "Original");

    quick_sort(arr, size, 0, size - 1);

    if (is_sorted(arr, size)) {
        printf("Is Sorted\n");
    } else {
        printf("\nFailed!!!\n");
        print_array_inline(arr, size, "Failed ");
    }

    /* print_array_inline(arr, size, "BEFORE_"); */
    /*  */
    /* res = partitioning(arr, size, 0, size - 1); */
    /* print_array_inline(arr, size, "\nAFTER_1"); */
    /* printf("RES: %d\n", res); */
    /*  */
    /* res = partitioning(arr, size, 0, size - 2); */
    /* print_array_inline(arr, size, "\nAFTER_2"); */
    /* printf("RES: %d\n", res); */
    /*  */
    /* res = partitioning(arr, size, 0, size - 3); */
    /* print_array_inline(arr, size, "\nAFTER_3"); */
    /* printf("RES: %d\n", res); */
}

int main()
{
    /* test_arr(); */
    /* return 0; */

    /* const int size = 10; */
    /* int arr[] = {2, 7, 10, 1, 9, 11, 5, 4, 12, 8, 6, 3}; */
    /* const int size = sizeof(arr) / sizeof(int); */

    const int size = 10;
    int * arr = generate_shuffled_array(size);

    printf("\nOriginal\n");
    print_array_inline(arr, size, "Original");

    quick_sort(arr, size, 0, size - 1);

    if (is_sorted(arr, size)) {
        printf("Is Sorted");
    } else {
        printf("\nFailed!!!\n");
        print_array_inline(arr, size, "Failed ");
    }

    return 0;
}

int test()
{
    const int size = 10;

    // Generate shuffled array
    /* int * rnd_arr = generate_random_values_array(size); */

    int rnd_arr[10] = {2, 9, 7, 1, 11, 5, 4, 10, 6, 3};

    print_array_inline(rnd_arr, size, "RND_ARR");

    int pivot = partitioning(rnd_arr, size, 0, size - 1);
    print_array_inline(rnd_arr, size, "\nPART1  ");
    printf("Pivot: %d\n\n", pivot); // 2

    int res = 0;

    //left
    int left_size = pivot;
    int left_begin = 0; // 0
    int left_end = left_size - 1; // 9
    res = partitioning(rnd_arr, left_size, left_begin, left_end);
    print_array_inline(rnd_arr, size, "PART2  ");
    printf("RES: %d\n\n", res); // 0

    // right
    int right_size = size - pivot - 1; // 7
    int right_begin = pivot + 1; // 3
    int right_end = size - 1; // 9
    res = partitioning(rnd_arr, right_size, right_begin, right_end);
    print_array_inline(rnd_arr, size, "PART3  ");
    printf("RES: %d\n\n", res); // 6

    // right 2 [3 to 5]
    int right2_size = res - right_begin;
    int right2_begin = right_begin; // 3
    int right2_end = res - 1; // 5
    res = partitioning(rnd_arr, right2_size, right2_begin, right2_end);
    print_array_inline(rnd_arr, size, "PART4   ");
    printf("RES: %d\n\n", res); //

    res = partitioning(rnd_arr, 3, 7, 9);
    print_array_inline(rnd_arr, size, "PART5   ");
    printf("RES: %d\n\n", res); //

    return 0;

    print_array(rnd_arr, size, "RND_ARR");

    // Sort shuffled array
    Result sort_res = bench_quick_sort(rnd_arr, size);

    print_array(sort_res.arr, size, "SORTED");

    // Output the results
    if (! is_sorted(sort_res.arr, size)) {
        printf("1. The result array is NOT sorted as expected\n");
    } else {
        printf("1. The result array is sorted as expected\n");
        printf("2. Time to quick sort the array: %.0f ms\n", sort_res.time);
    }

    free(rnd_arr);

    return 0;
}
