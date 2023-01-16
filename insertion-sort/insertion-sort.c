#include <stdio.h>
#include <stdlib.h>

const int LEN = 14;

void print_array(int *arr)
{
    for (int i = 0; i < LEN; i++) {
        printf("[%d]: %d\n", i, arr[i]);
    }
}

void print_arrays(int *arr, int *res)
{
    printf("\nArr --------------------------\n");
    print_array(arr);
    printf("\nRes --------------------------\n");
    print_array(res);
}

void set_first_two_elems(int *arr, int *res)
{
    if (arr[0] < arr[1]) {
        res[0] = arr[0];
        res[1] = arr[1];
    } else {
        res[0] = arr[1];
        res[1] = arr[0];
    }
}

int find_position_for_subject(int limit, int *arr, int *res)
{
    int position = 0;
    while (position < limit && res[position] < arr[limit]) position++;
    return position;
}

void shift_elements_to_right_backwards_till_position(int position, int length, int *result)
{
    for (int k = length - 1; k >= position; k--) {
        result[k] = result[k - 1];
    }
}

int main()
{
    int arr[] = {5, 2, 4, 9, 12, 6, 8, 10, 11, 1, 3, 13, 7, 14};
    int *res = malloc(sizeof(arr));
    set_first_two_elems(arr, res);
    for (int i = 2; i < LEN; i++) {
        int position = find_position_for_subject(i, arr, res);
        shift_elements_to_right_backwards_till_position(position, LEN, res);
        res[position] = arr[i];
    }
    /* print_arrays(arr, res); */
    free(res);
    return 0;
}
