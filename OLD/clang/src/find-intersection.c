#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../headers/Arrays.h"

typedef struct {
    int * arr;
    int size;
} ResultArray;

ResultArray non_optimized_intersection(const int arr1[],
                                       const int size1,
                                       const int arr2[],
                                       const int size2)
{
    // Take from arr1 what is present in arr2
    int * res = malloc(size1 * size1 * sizeof(int)); // Size1 picked at random
    int r = 0;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                res[r] = arr1[i];
                r++;
                break;
            }
        }
    }

    // Remove duplicate values
    int * res2 = malloc(r * sizeof(int));
    int r2 = 0;
    for (int i = 0; i < r; i++) {
        bool unique = true;
        for (int j = i + 1; j < r; j++) {
            if (res[i] == res[j]) {
                unique = false;
                break;
            }
        }
        if (unique) {
            res2[r2] = res[i];
            r2++;
        }
    }

    return (ResultArray) {res2, r2};
}

int main()
{
    const int size1 = 20;
    const int size2 = 20;

    const int limit1 = 10;
    const int limit2 = 50;

    int * arr1 = generate_limited_random_values_array(size1, limit1);
    int * arr2 = generate_limited_random_values_array(size2, limit2);

    // Get Instersection of both arrays
    ResultArray res = non_optimized_intersection(arr1, size1, arr2, size2);

    print_array(arr1, size1, "Arr1");
    print_array(arr2, size2, "Arr2");
    print_array_inline(res.arr, res.size, "Res");

    free(arr1);
    free(arr2);
    free(res.arr);

    return 0;
}
