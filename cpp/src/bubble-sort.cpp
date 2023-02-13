#include "../headers/Arrays.h"
#include "../headers/Time.h"

#include <cmath>

using std::cout;

std::shared_ptr<int[]> _bubble_sort(std::shared_ptr<int[]> arr, const int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j > i; j--) {
            if (arr[j - 1] > arr[j]) {
                std::swap(arr[j - 1], arr[j]);
            }
        }
    }
    return arr;
}

Result bubble_sort(const std::shared_ptr<int[]> arr, const int size)
{
    auto arr_copy = copy_array(arr, size);
    auto start = clock();
    auto res = _bubble_sort(arr_copy, size);
    auto end = clock();
    auto sortTime = get_time_ms(start, end);
    return (Result) {res, sortTime};
}

int main()
{
    const int size = 40000;

    // Generate shuffled array
    auto genResult = generate_shuffled_array(size);

    // Sort shuffled array
    auto sortResult = bubble_sort(genResult.arr, size);

    // Eval sorted array with an expected result
    auto expected = generate_expected_array(size);

    // Output the results
    cout << "1. Time to generate array of size " << size << ": "
         << floor(genResult.time) << " ms\n";
    if (! is_sorted_as_expected(sortResult.arr, expected, size)) {
        cout << "2. The result array is NOT sorted as expected\n";
    } else {
        cout << "2. The result array is sorted as expected\n";
        cout << "3. Time to bubble sort the array: "
             << floor(sortResult.time) << " ms\n";
    }

    return 0;
}
