#ifndef TIME_UTILS_H_INCLUDED
#define TIME_UTILS_H_INCLUDED

#include <time.h>
#include <stdbool.h>

typedef struct {
    double time;
    bool is_sorted;
} Benchmark_Result;

double get_time_ms(clock_t start, clock_t end);

#endif
