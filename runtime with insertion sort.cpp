#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> values(5150000);
    auto f = []() -> int { return rand() % 5150000; };
    generate(values.begin(), values.end(), f);
    auto start = high_resolution_clock::now();
    insertionSort(values);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by insertion sort: "
         << duration.count() << " microseconds" << endl;

    return 0;
}
