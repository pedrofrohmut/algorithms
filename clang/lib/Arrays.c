#include "../headers/Arrays.h"

#include "../headers/Time.h"

int * generate_shuffled_array(const int size)
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

Result bench_generate_shuffled_array(const int size)
{
    const clock_t start = clock();
    int * arr = generate_shuffled_array(size);
    const clock_t end = clock();
    return (Result) { arr, get_time_ms(start, end) };
}

int * generate_random_values_array(const int size)
{
    srand(time(NULL));
    int * arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % INT_MAX;
    }
    return arr;
}

Result bench_generate_random_values_array(const int size)
{
    const clock_t start = clock();
    int * arr = generate_random_values_array(size);
    const clock_t end = clock();
    return (Result) {arr, get_time_ms(start, end)};
}

int * get_ordered_copy(int * arr, const int size)
{
    int * copy = malloc(sizeof(int) * size);
    memcpy(copy, arr, sizeof(int) * size);
    // Insertion sort the array
    for (int i = 1; i < size; i++) {
        const int key = copy[i];
        int j = i;
        while (j > 0 && copy[j - 1] > key) {
            copy[j] = copy[j - 1];
            j--;
        }
        copy[j] = key;
    }
    return copy;
}

void swap(int * a, int * b)
{
    const int temp = *a;
    *a = *b;
    *b = temp;
}

int * generate_expected_array(const int size)
{
    int * expected = malloc(sizeof(int) * size);
    for (int i = 1; i <= size; i++) expected[i - 1] = i;
    return expected;
}

bool is_sorted_as_expected(int * sorted, int * expected, const int size)
{
    for (int i = 0; i < size; i++) {
        if (sorted[i] != expected[i]) return false;
    }
    return true;
}

bool is_sorted(int * arr, const int size)
{
    for (int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1]) return false;
    return true;
}

bool are_not_founds(int * positions, const int size)
{
    for (int i = 0; i < size; i++) {
        if (positions[i] < 0) return true;
    }
    return false;
}

void print_array(int * arr, const int size, char * name)
{
    for (int i = 0; i < size; i++)
        printf("%s [%d] = %d\n", name, i, arr[i]);
}
