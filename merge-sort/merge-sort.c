#include <stdio.h> // printf
#include <stdlib.h> // malloc
#include <time.h> // clock
#include <math.h> // floor
#include <stdbool.h> // bool

typedef struct Left_And_Right {
    int * left;
    int * right;
} LeftAndRight ;

double get_time_ms(clock_t start, clock_t end)
{
    double time_sec = (double) (end - start) / CLOCKS_PER_SEC;
    return time_sec * 1000;
}

int * get_expected_array(int size)
{
    int * expected = malloc(sizeof(int) * size);
    for (int i = 1; i <= size; i++) expected[i - 1] = i;
    return expected;
}

bool compare_arrays(int * merged, int * expected, int size)
{
    for (int i = 0; i < size; i++) {
        if (merged[i] != expected[i]) return false;
    }
    return true;
}

int * generate_array(int size)
{
    int * arr = malloc(sizeof(int) * size);
    for (int i = 1; i <= size; i++) {
        const int index = rand() % i;
        for (int j = size - 1; j >= index; j--) {
            arr[j] = arr[j - 1];
        }
        arr[index] = i;
    }
    return arr;
}

LeftAndRight get_left_and_right(int * arr, int left_size, int right_size)
{
    int * left = malloc(left_size * sizeof(int));
    int * right = malloc(right_size * sizeof(int));
    for (int i = 0; i < left_size; i++) { left[i]  = arr[i]; }
    for (int i = 0; i < right_size; i++) { right[i] = arr[left_size + i]; }
    return (LeftAndRight){ left, right };
}

int * insertion_sort(int * arr, int size)
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
    return arr;
}

int * merge_sort(int * left, int * right, int left_size, int right_size)
{
    const int full_size = left_size + right_size;
    int * merged = malloc(full_size * sizeof(int));
    int l = 0; // left index
    int r = 0; // right index
    for (int i = 0; i < full_size; i++) {
        if (l >= left_size) {
            for (int i = r; i < right_size; i++) {
                merged[i + l] = right[i];
            }
            break;
        }
        if (r >= right_size) {
            for (int i = l; i < left_size; i++) {
                merged[i + r] = left[i];
            }
            break;
        }
        if (left[l] < right[r]) {
            merged[i] = left[l];
            l++;
        } else {
            merged[i] = right[r];
            r++;
        }
    }
    return merged;
}

int main()
{
    const int size = 30000;
    const int extra = size % 2 == 0 ? 0 : 1;
    const int left_size = size / 2 + extra;
    const int right_size = size / 2;

    // Generate array
    const clock_t gen_start = clock();
    int * arr = generate_array(size);
    const clock_t gen_end = clock();

    const clock_t sort_start = clock();

    // Get left and right. The halves of the array
    const LeftAndRight left_and_right = get_left_and_right(arr, left_size, right_size);

    // Sort left and right (insertion sort)
    int * left = insertion_sort(left_and_right.left, left_size);
    int * right = insertion_sort(left_and_right.right, right_size);

    // Merge left and right
    int * merged = merge_sort(left, right, left_size, right_size);

    const clock_t sort_end = clock();

    // Eval sorted array with an expected result
    int * expected = get_expected_array(size);
    const bool are_equal = compare_arrays(merged, expected, size);

    // Output the results
    printf("1. Time to generate array: %.f ms\n", get_time_ms(gen_start, gen_end));
    if (! are_equal) {
        printf("2. Result array is NOT sorted as expected\n");
    } else {
        printf("2. Result array is sorted as expected\n");
        printf("3. Time to merge sort the array: %.f ms\n", get_time_ms(sort_start, sort_end));
    }

    free(arr);
    free(left_and_right.left);
    free(left_and_right.right);
    free(merged);
    free(expected);
    return 0;
}
