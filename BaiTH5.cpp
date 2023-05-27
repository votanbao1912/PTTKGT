#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Hàm hoán ??i giá tr? c?a hai ph?n t?
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm ch?n v? trí m?c ng?u nhiên
int randomPivot(int arr[], int low, int high) {
    srand(time(NULL));
    int random = low + rand() % (high - low);
    return random;
}

// Hàm phân ho?ch (partition)
int partition(int arr[], int low, int high) {
    int pivotIndex = randomPivot(arr, low, high); // Ch?n v? trí m?c ng?u nhiên
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[high]); // ??a v? trí m?c v? cu?i m?ng
    int i = low - 1; // V? trí phân ho?ch cu?i cùng

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivotValue) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // ??a v? trí m?c v? ?úng v? trí
    return i + 1;
}

// Hàm s?p x?p QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// Hàm in m?ng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Hàm chính
int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Mang ban dau: ";
    printArray(arr, size);
    
    quickSort(arr, 0, size - 1);
    
    cout << "Mang sau khi sap xep: ";
    printArray(arr, size);
    
    return 0;
}

