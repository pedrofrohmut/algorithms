#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int * generate_array(int size)
{
    int * arr = malloc(sizeof(int) * size);
    for (int i = 1; i <= size; i++) {
        int index = floor(rand() % i);
        for (int j = size - 1; j >= index; j--) {
            arr[j] = arr[j - 1];
        }
        arr[index] = i;
    }
    return arr;
}

double get_time_ms(clock_t start, clock_t end)
{
    double time_sec = (double) (end - start) / CLOCKS_PER_SEC;
    double time_ms = time_sec * 1000;
    return time_ms;
}

int * get_expected_array(int size)
{
    int * expected = malloc(sizeof(int) * size);
    for (int i = 1; i <= size; i++) expected[i - 1] = i;
    return expected;
}

int compare_arrays(int * res, int * expected, int size)
{
    for (int i = 0; i < size; i++) {
        if (res[i] != expected[i]) return 0;
    }
    return 1;
}

void insertion_sort(int * arr, int size)
{
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    const int size = 30000;

    // Generate array
    clock_t generate_start = clock();
    int * arr = generate_array(size);
    clock_t generate_end = clock();

    double generate_time_ms = get_time_ms(generate_start, generate_end);
    printf("1. Time to generate array: %.4f ms\n", generate_time_ms);

    // Sort array
    clock_t sort_start = clock();
    insertion_sort(arr, size);
    clock_t sort_end = clock();

    // Eval sorted array with an expected result
    int * expected = get_expected_array(size);
    int are_equal = compare_arrays(arr, expected, size);
    if (! are_equal) {
        printf("2. They are NOT equal\n");
    } else {
        printf("2. Result array is sorted as expected\n");
        double sort_time_ms = get_time_ms(sort_start, sort_end);
        printf("3. Time to sort the array: %.4f ms\n", sort_time_ms);
    }

    free(arr);
    free(expected);
    return 0;
}
