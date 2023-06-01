#include <iostream>
#include <vector>

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to partition the array
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose the rightmost element as the pivot
    int i = (low - 1);      // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;  // Increment the index of the smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Function to implement Quick Sort
void quickSortHelper(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the sub-arrays
        quickSortHelper(arr, low, pivotIndex - 1);
        quickSortHelper(arr, pivotIndex + 1, high);
    }
}

void quickSort(std::vector<int>& arr)
{
    quickSortHelper(arr, 0, arr.size() - 1);
}

// Function to print the array
//void printArray(const std::vector<int>& arr) {
//    for (int num : arr) {
//        std::cout << num << " ";
//    }
//    std::cout << std::endl;
//}

// Example usage
//int main() {
//    std::vector<int> arr = { 9, 1, 6, 3, 2, 8, 4, 7, 5 };
//
//    std::cout << "Original array: ";
//    printArray(arr);
//
//    quickSort(arr);
//
//    std::cout << "Sorted array: ";
//    printArray(arr);
//
//    return 0;
//}
