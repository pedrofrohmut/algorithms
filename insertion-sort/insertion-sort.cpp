// int main()
// {
//     vector<int> arr = {5, 2, 4, 6, 1, 3};
//     vector<int> res = {};
//
//     if (arr.size() < 2) return 1;
//
//     if (arr.at(0) < arr.at(1)) {
//         res.push_back(arr.at(0));
//         res.push_back(arr.at(1));
//     } else {
//         res.push_back(arr.at(1));
//         res.push_back(arr.at(0));
//     }
//
//     for (auto i = 2; i < arr.size(); i++) {
//         auto j = 0;
//         while (j < res.size() && res.at(j) < arr.at(i)) {
//             j++;
//         }
//         if (j == res.size()) {
//             res.push_back(arr.at(i));
//         } else {
//             res.insert(res.begin() + j, arr[i]);
//         }
//     }
//
//     cout << "\nArr" << endl;
//     for (auto& v : arr) {  cout << v << " " << endl; }
//     cout << "\nRes" << endl;
//     for (auto& v : res) { cout << v << " " << endl; }
//
//     return 0;
// }

#include <vector>
#include <iostream>
#include <array>

#include <stdlib.h>
#include <time.h>

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

    // Evaul sorted array with an expected result
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
