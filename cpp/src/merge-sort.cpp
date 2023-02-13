#include "../headers/Arrays.h"
#include "../headers/Time.h"

#include <cmath>

using std::cout;

std::shared_ptr<int[]> _merge(std::shared_ptr<int[]> left,
                              std::shared_ptr<int[]> right,
                              const int left_size,
                              const int right_size)
{
    std::shared_ptr<int[]> res(new int[left_size + right_size]);
    int res_index = 0;
    int left_index = 0;
    int right_index = 0;

    // Merge sorted values to res until left or right index reaches its size
    while (left_index < left_size && right_index < right_size) {
        if (left[left_index] < right[right_index]) {
            res[res_index] = left[left_index];
            left_index++;
        } else {
            res[res_index] = right[right_index];
            right_index++;
        }
        res_index++;
    }

    // Add remainders from left to res. If any
    while (left_index < left_size) {
        res[res_index] = left[left_index];
        left_index++;
        res_index++;
    }

    // Add remainders from right to res. If any
    while (right_index < right_size) {
        res[res_index] = right[right_index];
        right_index++;
        res_index++;
    }
    return res;
}

std::shared_ptr<int[]> _merge_sort(std::shared_ptr<int[]> arr, const int size)
{
    // Recursion escape condition
    if (size == 1) return arr;

    // Sizes
    const int left_size = ceil((float) size / 2);
    const int right_size = size / 2;

    // Devide in halves left and right
    std::shared_ptr<int[]> left(new int[left_size]);
    for (int i = 0; i < left_size; i++) left[i] = arr[i];
    std::shared_ptr<int[]> right(new int[right_size]);
    for (int i = left_size; i < size; i++) right[i - left_size] = arr[i];

    // Recursion
    auto sorted_left = _merge_sort(left, left_size);
    auto sorted_right = _merge_sort(right, right_size);

    // Merge sorted halves
    auto merged = _merge(sorted_left, sorted_right, left_size, right_size);
    return merged;
}

Result merge_sort(const std::shared_ptr<int[]> arr, const int size)
{
    auto arr_copy = copy_array(arr, size);
    auto start = clock();
    auto res = _merge_sort(arr_copy, size);
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
    auto sortResult = merge_sort(genResult.arr, size);

    // Eval sorted array with an expected result
    auto expected = generate_expected_array(size);

    // Output the results
    cout << "1. Time to generate array of size " << size << ": "
         << floor(genResult.time) << " ms\n";
    if (! is_sorted_as_expected(sortResult.arr, expected, size)) {
        cout << "2. The result array is NOT sorted as expected\n";
    } else {
        cout << "2. The result array is sorted as expected\n";
        cout << "3. Time to merge sort the array: "
             << floor(sortResult.time) << " ms\n";
    }

    return 0;
}
