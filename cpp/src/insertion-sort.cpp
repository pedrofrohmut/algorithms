#include "../headers/Arrays.h"
#include "../headers/Time.h"

#include <cmath>

using std::cout;

std::shared_ptr<int[]> _insertion_sort(std::shared_ptr<int[]> arr, const int size)
{
    for (int i = 1; i < size; i++)
    {
        const int key = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
    return arr;
}

Result insertion_sort(const std::shared_ptr<int[]> arr, const int size)
{
    auto copy = copy_array(arr, size);
    auto start = clock();
    auto res = _insertion_sort(copy, size);
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
    auto sortResult = insertion_sort(genResult.arr, size);

    // Eval sorted array with an expected result
    auto expected = generate_expected_array(size);

    // Output the results
    cout << "1. Time to generate array of size " << size << ": "
         << floor(genResult.time) << " ms\n";
    if (! is_sorted_as_expected(sortResult.arr, expected, size)) {
        cout << "2. The result array is NOT sorted as expected\n";
    } else {
        cout << "2. The result array is sorted as expected\n";
        cout << "3. Time to insertion sort the array: "
             << floor(sortResult.time) << " ms\n";
    }

    return 0;
}
