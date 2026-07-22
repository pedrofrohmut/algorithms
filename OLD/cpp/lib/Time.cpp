#include "../headers/Time.h"

double get_time_ms(clock_t start, clock_t end)
{
    double time_sec = (double) (end - start) / CLOCKS_PER_SEC;
    return time_sec * 1000;
}

