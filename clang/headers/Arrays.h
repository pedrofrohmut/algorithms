#ifndef ARRAYS_H_INCLUDED
#define ARRAYS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int * generate_shuffled_array(int size);

int * generate_expected_array(int size);

bool is_sorted_as_expected(int * sorted, int * expected, int size);

void print_array(int * arr, int size, char * name);

#endif
