#include <iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition the array around the middle value
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Middle value as pivot
    int i = low;
    int j = high;

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return i;
}

// Sort the array around the middle value recursively
void sortMiddle(int arr[], int low, int high) {
    if (low < high) {
        int middle = partition(arr, low, high);
        sortMiddle(arr, low, middle - 1); // Sort the left side
        sortMiddle(arr, middle, high);    // Sort the right side
    }
}

void sortAroundMiddle(int arr[], int n) {
    // Find the middle index
    int middle = n / 2;
    
    // Swap the middle value to the beginning of the array
    swap(arr[0], arr[middle]);
    
    // Sort left and right sides independently
    sortMiddle(arr, 1, n - 1);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {3,4,2,8,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Original Array:" << std::endl;
    printArray(arr, n);
    sortAroundMiddle(arr, n);
    std::cout << "\nSorted left and right sides from middle value:" << std::endl;
    printArray(arr, n);
    return 0;
}
