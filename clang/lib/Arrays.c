#include "../headers/Arrays.h"

int * generate_shuffled_array(int size)
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

int * generate_expected_array(int size)
{
    int * expected = malloc(sizeof(int) * size);
    for (int i = 1; i <= size; i++) expected[i - 1] = i;
    return expected;
}

bool is_sorted_as_expected(int * sorted, int * expected, int size)
{
    for (int i = 0; i < size; i++) {
        if (sorted[i] != expected[i]) return false;
    }
    return true;
}

void print_array(int * arr, int size, char * name)
{
    for (int i = 0; i < size; i++)
        printf("%s [%d] = %d\n", name, i, arr[i]);
}
