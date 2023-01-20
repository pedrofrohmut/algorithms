#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int len)
{
    for (int i = 0; i < len; i++) printf("[%d]: %d\n", i, arr[i]);
}

typedef struct Left_And_Right {
    int * Left;
    int * Right;
} LeftAndRight ;

LeftAndRight get_left_and_right(int * arr, int arr_size)
{
    int extra = arr_size % 2 == 0 ? 0 : 1;
    int size = arr_size / 2;
    int * left = malloc((size + extra) * sizeof(int));
    int * right = malloc(size * sizeof(int));
    for (int i = 0; i < size + extra; i++) { left[i]  = arr[i]; }
    for (int i = 0; i < size; i++) { right[i] = arr[size + i]; }
    return (LeftAndRight){ left, right };
}

int * order_array(int * arr, int len)
{
    if (len < 2)  return arr;
    int * res = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)  res[i] = arr[i];
    for (int i = 1; i < len; i++) {
        int j = 0;
        while (j < i && res[j] < arr[i]) j++;
        if (j == i) {
            res[i] = arr[i];
        } else {
            for (int k = len - 1; k >= j; k--) res[k] = res[k - 1];
            res[j] = arr[i];
        }
    }
    return res;
}

int * merge_sort(int * left, int lsize, int * right, int rsize)
{
    int res_len = lsize + rsize;
    int * res = malloc(res_len * sizeof(int));
    int l = 0;
    int r = 0;
    for (int i = 0; i < res_len; i++) {
        if (r >= rsize || l >= lsize) break;
        if (left[l] < right[r]) {
            res[i] = left[l];
            l++;
        } else {
            res[i] = right[r];
            r++;
        }
    }
    // Add final remaining elements if there are any
    if (r < rsize) {
        for (int i = r; i < rsize; i++)  res[i + l] = right[i];
    }
    if (l < lsize) {
        for (int i = l; i < lsize; i++)  res[i + r] = left[i];
    }
    return res;
}

int main()
{
    int arr[] = { 5, 30, 34, 19, 20, 31, 33, 2, 15, 41, 32, 25, 17, 38, 4, 6, 23, 29, 40, 14, 7, 36, 21, 1, 16, 39, 26, 35, 9, 12, 13, 24, 3, 37, 18, 27, 10, 8, 28, 11, 22 };
    int size = sizeof(arr) / sizeof(int);

    // Get Left and Right from source array
    LeftAndRight left_and_right = get_left_and_right(arr, size);
    int * left = left_and_right.Left;
    int * right = left_and_right.Right;
    int lsize, rsize;
    if (size % 2 == 0) {
        lsize = rsize = size / 2;
    } else {
        rsize = size / 2;
        lsize = (size / 2) + 1;
    }

    // Order Left and Right
    left = order_array(left, lsize);
    right = order_array(right, rsize);

    // MergeSort the two halves
    int * res = merge_sort(left, lsize, right, rsize);

    /* print_array(res, size); */

    free(left);
    free(right);
    return 0;
}
