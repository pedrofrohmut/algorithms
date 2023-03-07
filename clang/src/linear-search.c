#include <stdio.h>
#include <stdlib.h> // malloc

#include "../headers/Arrays.h"
#include "../headers/Time.h"

const int linear_search(const int arr[], const int size, const int value)
{
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

Result bench_linear_search(const int arr[], const int sorted[], const int size)
{
    int * positions = malloc(sizeof(int) * size);
    const clock_t start = clock();
    for (int i = 0; i < size; i++) {
        const int value = sorted[i];
        const int pos = linear_search(arr, size, value);
        positions[i] = pos;
    }
    const clock_t end = clock();
    const double searchTime = get_time_ms(start, end);
    return (Result) {positions, searchTime};
}

int main()
{
    const int size = 40000;

    // Generate Shuffled Array
    int * rnd_arr = generate_random_values_array(size);
    int * ord_cpy = get_ordered_copy(rnd_arr, size);

    // Bench linear search all results
    Result schResult = bench_linear_search(rnd_arr, ord_cpy, size);

    // Check positions for any -1 (not found)
    bool are_not_found = are_not_founds(schResult.arr, size);

    // Output results
    if (are_not_founds(schResult.arr, size)) {
        printf("1. The linear search did NOT found all values\n");
    } else {
        printf("1. The linear search did found all values\n");
        printf("2. Time to linear search all the values in the shuffled array of"
                " size %d: %.0f ms\n", size, schResult.time);
    }

    free(rnd_arr);
    free(ord_cpy);
    free(schResult.arr);

    return 0;
}
