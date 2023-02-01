#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int get_index(int i) { return rand() % i; }

int * generate_array(int size)
{
    int * generated = malloc(sizeof(int) * size);
    for (int i = 1; i <= size; i++) {
        int index = get_index(i);
        for (int j = size - 1; j >= index; j--) {
            generated[j] = generated[j - 1];
        }
        generated[index] = i;
    }
    return generated;
}

int * insertion_sort(int * arr, int size)
{
    int * res = malloc(sizeof(int) * size);
    res[0] = arr[0];
    for (int i = 1; i < size; i++) {
        // insert_position
        int j = 0;
        while (j < i && res[j] < arr[i]) j++;
        if (j == i) {
            res[i] = arr[i];
        } else {
            // Move to +1 cells right (higher) to j (insert position)
            for (int k = i; k >= j; k--) res[k] = res[k - 1];
            res[j] = arr[i];
        }
    }
    return res;
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

int main()
{
    const int size = 30000;
    int * arr = generate_array(size);

    clock_t start = clock();
    int * res = insertion_sort(arr, size);
    clock_t end = clock();

    int * expected = get_expected_array(size);

    int are_equal = compare_arrays(res, expected, size);
    if (! are_equal) {
        printf("They are NOT equal\n");
    } else {
        printf("Result array is as expected\n");
        printf("Sorted in %f milliseconds\n", get_time(start, end));
    }

    free(res);
    free(arr);
    free(expected);
    return 0;
}
