#include <iostream>
#include <vector>

using namespace std;

int get_index(int i) { return rand() % i; }

vector<int> generate_array(int size)
{
    vector<int> arr = {};
    for (auto i = 1; i <= size; i++) {
        int index = get_index(i);
        arr.insert(arr.begin() + index, i);
    }
    return arr;
}

vector<int> insertion_sort(vector<int> arr)
{
    vector<int> res = {};
    res.push_back(arr[0]);
    for (auto i = 1; i < arr.size(); i++) {
        auto j = 0;
        while (j < i && res[j] < arr[i]) { j++; }
        res.insert(res.begin() + j, arr[i]);
    }
    return res;
}

vector<int> get_expected_array(int size)
{
    vector<int> arr = {};
    for (auto i = 1; i <= size; i++) {
        arr.push_back(i);
    }
    return arr;
}

bool compare_arrays(vector<int> subject, vector<int> expected)
{
    for (auto i = 0; i < subject.size(); i++) {
        if (subject[i] != expected[i]) return false;
    }
    return true;
}

double get_time_ms(clock_t start, clock_t end)
{
    auto time_sc = (double) (end - start) / CLOCKS_PER_SEC;
    return time_sc * 1000;
}

int main()
{
    const int size = 30000;

    // Generate array
    auto gen_start = clock();
    auto arr = generate_array(size);
    auto gen_end = clock();

    auto sort_start = clock();

    // Sort array
    auto res = insertion_sort(arr);

    // Eval sorted array with an expected result
    auto expected = get_expected_array(size);
    auto are_equal = compare_arrays(res, expected);

    auto sort_end = clock();

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
