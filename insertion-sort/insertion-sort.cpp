#include <iostream>
#include <array>

using namespace std;

const int SIZE = 30000;

int get_index(int i) { return rand() % i; }

array<int, SIZE> generate_array()
{
    srand(time(NULL));
    array<int, SIZE> arr = {};
    for (auto i = 1; i <= SIZE; i++) {
        auto index = get_index(i);
        for (auto j = SIZE - 1; j >= index; j--) {
            arr[j] = arr[j - 1];
        }
        arr[index] = i;
    }
    return arr;
}

array<int, SIZE> insertion_sort(array<int, SIZE> arr)
{
    for (auto i = 1; i < SIZE; i++) {
        auto key = arr[i];
        auto j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return arr;
}

double get_time_ms(clock_t start, clock_t end)
{
    auto time_sc = (double) (end - start) / CLOCKS_PER_SEC;
    return time_sc * 1000;
}

array<int, SIZE> get_expected_array()
{
    array<int, SIZE> arr = {};
    for (auto i = 0; i < SIZE; i++) {
        arr[i] = i + 1;
    }
    return arr;
}

bool compare_arrays(array<int, SIZE> subject, array<int, SIZE> expected)
{
    for (auto i = 0; i < SIZE; i++) {
        if (subject[i] != expected[i]) return false;
    }
    return true;
}

int main()
{
    // Generate array
    auto gen_start = clock();
    auto arr = generate_array();
    auto gen_end = clock();

    // Sort array
    auto sort_start = clock();
    auto res = insertion_sort(arr);
    auto sort_end = clock();

    // Eval sorted array with an expected result
    auto expected = get_expected_array();
    auto are_equal = compare_arrays(res, expected);

    // Output results
    cout << "1. Time to generate array: " << get_time_ms(gen_start, gen_end) << " ms" << endl;
    if (! are_equal) {
        cout << "2. Result array is NOT sorted as expected" << endl;
    } else {
        cout << "2. Result array is sorted as expected" << endl;
        cout << "3. Time to sort array: " << get_time_ms(sort_start, sort_end) << " ms" << endl;
    }

    return 0;
}
