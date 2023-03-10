#ifndef ARRAYS_H_INCLUDED
#define ARRAYS_H_INCLUDED

#include <stdbool.h> // bool

typedef struct {
    int * arr;
    double time;
} Result;

int * generate_shuffled_array(const int size);

Result bench_generate_shuffled_array(const int size);

int * generate_random_values_array(const int size);

int * generate_limited_random_values_array(const int size, const int limit);

Result bench_generate_random_values_array(const int size);

int * get_ordered_copy(const int arr[], const int size);

void swap(int * a, int * b);

int * generate_expected_array(const int size);

bool is_sorted_as_expected(int * sorted, int * expected, const int size);

bool is_sorted(int * arr, const int size);

bool are_not_founds(int * positions, const int size);

void print_array(int * arr, const int size, char * name);

void print_array_inline(int * arr, const int size, char * name);

int * copy_array(const int arr[], const int size);

#endif
