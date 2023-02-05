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

double get_time(clock_t start, clock_t end)
{
    return ((double) (end - start) / CLOCKS_PER_SEC) * 1000;
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
    const clock_t gen_start = clock();
    int * arr = generate_array(size);
    const clock_t gen_end = clock();

    printf("1. Time to generate array: %.4f ms\n", get_time(gen_start, gen_end));

    // Sort array
    const clock_t sort_start = clock();
    insertion_sort(arr, size);
    const clock_t sort_end = clock();

    // Eval sorted array with an expected result
    int * expected = get_expected_array(size);
    const int are_equal = compare_arrays(arr, expected, size);

    // Output the results
    if (! are_equal) {
        printf("2. The result array is NOT sorted as expected\n");
    } else {
        printf("2. The result array is sorted as expected\n");
        printf("3. Time to sort the array: %.4f ms\n", get_time(sort_start, sort_end));
    }

    free(arr);
    free(expected);
    return 0;
}
