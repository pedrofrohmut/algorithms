#include <stdio.h>
#include <string.h>

#include "../headers/Arrays.h"
#include "../headers/Time.h"

void _swap(int * a, int * b)
{
    const int temp = *a;
    *a = *b;
    *b = temp;
}

int * _bubble_sort(int * arr, int size)
{
    int * res = malloc(sizeof(int) * size);
    memcpy(res, arr, sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j > i; j--) {
            if (res[j] < res[j - 1]) {
                _swap(&res[j], &res[j - 1]);
            }
        }
    }

    return res;
}

Result bubble_sort(int * arr, int size)
{
    const clock_t start = clock();
    int * result_array = _bubble_sort(arr, size);
    const clock_t end = clock();
    Result result = { result_array, get_time_ms(start, end) };
    return result;
}

int main()
{
    const int size = 40000;

    // Generate Array
    Result genResult = generate_shuffled_array(size);

    // Sort array
    Result sortResult = bubble_sort(genResult.arr, size);

    // Eval sorted array with an expected result
    int * expected = generate_expected_array(size);

    // Output the results
    printf("1. Time to generate the array of size %d: %.4f ms\n", size, genResult.time);
    if (! is_sorted_as_expected(sortResult.arr, expected, size)) {
        printf("2. The result array is NOT sorted as expected\n");
    } else {
        printf("2. The result array is sorted as expected\n");
        printf("3. Time to bubble sort the array: %.4f ms\n", sortResult.time);
    }

    free(genResult.arr);
    free(sortResult.arr);
    free(expected);
    return 0;
}
