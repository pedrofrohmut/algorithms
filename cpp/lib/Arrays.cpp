#include "../headers/Arrays.h"

using std::cout;

double _get_time_ms(clock_t start, clock_t end)
{
    double time_sec = (double) (end - start) / CLOCKS_PER_SEC;
    return time_sec * 1000;
}

std::shared_ptr<int[]> _generate_shuffled_array(const int size)
{
    srand(time(NULL));
    std::shared_ptr<int[]> arr(new int[size]);
    for (int i = 1; i <= size; i++) {
        const int index = rand() % i;
        for (int j = size - 1; j > index; j--) {
            arr[j] = arr[j - 1];
        }
        arr[index] = i;
    }
    return arr;
}

Result generate_shuffled_array(const int size)
{
    clock_t start = clock();
    auto arr = _generate_shuffled_array(size);
    clock_t end = clock();
    double genTime = _get_time_ms(start, end);
    return (Result) {arr, genTime};
}

std::shared_ptr<int[]> generate_expected_array(const int size)
{
    std::shared_ptr<int[]> expected(new int[size]);
    for (int i = 0; i < size; i++) {
        expected[i] = i + 1;
    }
    return expected;
}

bool is_sorted_as_expected(std::shared_ptr<int[]> sorted,
                           std::shared_ptr<int[]> expected,
                           const int size)
{
    for (int i = 0; i < size; i++) {
        if (sorted[i] != expected[i])  return false;
    }
    return true;
}

void print_array(const std::shared_ptr<int[]> arr, const int size, const string name)
{
    for (int i = 0; i < size; i++) {
        cout << name << "[" << i << "] = " << arr[i] << "\n";
    }
}

std::shared_ptr<int[]> copy_array(const std::shared_ptr<int[]> src, const int size)
{
    std::shared_ptr<int[]> copy(new int[size]);
    for (int i = 0; i < size; i++) copy[i] = src[i];
    return copy;
}
