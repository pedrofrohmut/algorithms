#include "../headers/Arrays.h"
#include "../headers/Time.h"

#include <cmath>

using std::cout;

std::shared_ptr<int[]> _selection_sort(std::shared_ptr<int[]> src, const int size)
{
    std::shared_ptr<int[]> res(new int[size]);
    for (int i = 0; i < size; i++) {
        int min_pos = 0;
        int j = 0;
        const int src_size = size - i;
        while (j < src_size) {
            if (src[j] < src[min_pos]) min_pos = j;
            j++;
        }
        res[i] = src[min_pos];
        for (int k = min_pos; k < src_size; k++) {
            src[k] = src[k + 1];
        }
    }
    return res;
}

Result selection_sort(const std::shared_ptr<int[]> arr, const int size)
{
    auto arr_copy = copy_array(arr, size);
    auto start = clock();
    auto res = _selection_sort(arr_copy, size);
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
    auto sortResult = selection_sort(genResult.arr, size);

    // Eval sorted array with an expected result
    auto expected = generate_expected_array(size);

    // Output the results
    cout << "1. Time to generate array of size " << size << ": "
         << floor(genResult.time) << " ms\n";
    if (! is_sorted_as_expected(sortResult.arr, expected, size)) {
        cout << "2. The result array is NOT sorted as expected\n";
    } else {
        cout << "2. The result array is sorted as expected\n";
        cout << "3. Time to selection sort the array: "
             << floor(sortResult.time) << " ms\n";
    }

    return 0;
}
