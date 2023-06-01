#include <iostream>
#include <vector>

void slowSortRecursive(std::vector<int>& arr, int low, int high) {
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    slowSortRecursive(arr, low, mid);
    slowSortRecursive(arr, mid + 1, high);

    if (arr[high] < arr[mid])
        std::swap(arr[high], arr[mid]);

    slowSortRecursive(arr, low, high - 1);
}

void slowSort(std::vector<int>& arr) {
    int n = arr.size();
    slowSortRecursive(arr, 0, n - 1);
}

// int main() {
    // std::vector<int> arr = {4, 2, 1, 3};
    // slowSort(arr);

    // for (int num : arr) {
        // std::cout << num << " ";
    // }

    // return 0;
// }
