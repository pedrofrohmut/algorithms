#include <iostream>
#include <vector>

using std::cout;
using std::vector;

typedef struct {
    const vector<int> arr;
    const double time;
} Result;

double get_time_ms(clock_t start, clock_t end)
{
    auto time_sc = (double) (end - start) / CLOCKS_PER_SEC;
    return time_sc * 1000;
}


vector<int> _generate_array(int size)
{
    srand(time(NULL));
    vector<int> arr = {};
    for (auto i = 1; i <= size; i++) {
        int index = rand() % i;
        arr.insert(arr.begin() + index, i);
    }
    return arr;
}

Result generate_array(int size)
{
    const clock_t start = clock();
    const auto arr = _generate_array(size);
    const clock_t end = clock();
    const Result result = {arr, get_time_ms(start, end)};
    return result;
}

vector<int> _insertion_sort(vector<int> arr)
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

Result insertion_sort(vector<int> arr)
{
    const clock_t start = clock();
    const auto res = _insertion_sort(arr);
    const clock_t end = clock();
    const Result result = {res, get_time_ms(start, end)};
    return result;
}

vector<int> get_expected_array(int size)
{
    vector<int> arr = {};
    for (auto i = 1; i <= size; i++) {
        arr.push_back(i);
    }
    return arr;
}

bool is_sorted_as_expected(vector<int> subject, vector<int> expected)
{
    for (auto i = 0; i < subject.size(); i++) {
        if (subject[i] != expected[i]) return false;
    }
    return true;
}

int main()
{
    const int size = 40000;

    // Generate array
    auto genResult = generate_array(size);

    // Sort shuffled array
    auto sortResult = insertion_sort(genResult.arr);

    // Eval sorted array with an expected result
    auto expected = get_expected_array(size);

    // Output the results
    cout << "1. Time to generate array of size " << size << ": " << genResult.time << " ms\n";
    if (! is_sorted_as_expected(sortResult.arr, expected)) {
        cout << "2. The result array is NOT sorted as expected\n";
    } else {
        cout << "2. The result array is sorted as expected\n";
        cout << "3. Time to insertion sort the array: " << sortResult.time << " ms\n";
    }
    return 0;
}
