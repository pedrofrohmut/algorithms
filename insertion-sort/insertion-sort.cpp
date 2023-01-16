#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> arr = {5, 2, 4, 6, 1, 3};
    vector<int> res = {};

    if (arr.size() < 2) return 1;

    if (arr.at(0) < arr.at(1)) {
        res.push_back(arr.at(0));
        res.push_back(arr.at(1));
    } else {
        res.push_back(arr.at(1));
        res.push_back(arr.at(0));
    }

    for (auto i = 2; i < arr.size(); i++) {
        auto j = 0;
        while (j < res.size() && res.at(j) < arr.at(i)) {
            j++;
        }
        if (j == res.size()) {
            res.push_back(arr.at(i));
        } else {
            res.insert(res.begin() + j, arr[i]);
        }
    }

    cout << "\nArr" << endl;
    for (auto& v : arr) {  cout << v << " " << endl; }
    cout << "\nRes" << endl;
    for (auto& v : res) { cout << v << " " << endl; }

    return 0;
}
