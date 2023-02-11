#include "../headers/Arrays.h"

double _get_time_ms(clock_t start, clock_t end)
{
    double time_sec = (double) (end - start) / CLOCKS_PER_SEC;
    return time_sec * 1000;
}

int * _generate_shuffled_array(int size)
{
    srand(time(NULL));
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

Result generate_shuffled_array(int size)
{
    const clock_t start = clock();
    int * arr = _generate_shuffled_array(size);
    const clock_t end = clock();
    return (Result) { arr, _get_time_ms(start, end) };
}

void swap(int * a, int * b)
{
    const int temp = *a;
    *a = *b;
    *b = temp;
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
