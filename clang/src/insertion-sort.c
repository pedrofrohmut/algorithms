#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../headers/Arrays.h"
#include "../headers/Time.h"

typedef struct {
    double time;
    bool is_sorted;
} Benchmark_Result;

void insertion_sort(int * arr, const int size)
{
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

Benchmark_Result bench_insertion_sort(const int size)
{
    int * rnd_vals = generate_random_values_array(size);

    const clock_t start = clock();
    insertion_sort(rnd_vals, size);
    const clock_t end = clock();

    double time = get_time_ms(start, end);
    bool sort_worked = is_sorted(rnd_vals, size);
    free(rnd_vals);
    return (Benchmark_Result) { time, sort_worked };
}

int main()
{
    const int bench_amt = 10;
    const int size = 40000;
    double avg_time = 0;

    for (int i = 0; i < bench_amt; i++) {
        Benchmark_Result res = bench_insertion_sort(size);

        if (! res.is_sorted) {
            printf("ERROR: The array is NOT sorted as expected\n");
            return 1;
        }
        printf("%d. Array is sorted in %.0f ms\n", (i + 1), res.time);
        avg_time += res.time;
    }
    avg_time /= bench_amt;

    printf("BENCHMARK: The avarage time to insertion sort the %d arrays is %0.f ms\n",
            bench_amt, avg_time);
    return 0;
}
