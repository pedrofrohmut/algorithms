#ifndef ARRAYS_H_INCLUDED
#define ARRAYS_H_INCLUDED

#include <stdio.h> // printf
#include <stdlib.h> // malloc
#include <stdbool.h> // bool
#include <time.h> // clock_t
#include <limits.h> // INT_MAX

typedef struct {
    int * arr;
    double time;
} Result;

int * generate_shuffled_array(const int size);

Result bench_generate_shuffled_array(const int size);

int * generate_random_values_array(const int size);

Result bench_generate_random_values_array(const int size);

void swap(int * a, int * b);

int * generate_expected_array(const int size);

bool is_sorted_as_expected(int * sorted, int * expected, const int size);

bool are_not_founds(int * positions, const int size);

void print_array(int * arr, const int size, char * name);

#endif
