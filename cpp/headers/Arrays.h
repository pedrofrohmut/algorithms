#ifndef ARRAYS_H_INCLUDED
#define ARRAYS_H_INCLUDED

#include <memory>
#include <chrono>
#include <iostream>

using std::string;

typedef struct {
    std::shared_ptr<int[]> arr;
    double time;
} Result;

Result generate_shuffled_array(const int size);

std::shared_ptr<int[]> generate_expected_array(const int size);

bool is_sorted_as_expected(std::shared_ptr<int[]> sorted,
                           std::shared_ptr<int[]> expected,
                           const int size);

void print_array(const std::shared_ptr<int[]> arr, const int size, string name);

std::shared_ptr<int[]> copy_array(const std::shared_ptr<int[]> src, const int size);

#endif // ARRAYS_H_INCLUDED
