#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// H�m ho�n ??i gi� tr? c?a hai ph?n t?
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// H�m ch?n v? tr� m?c ng?u nhi�n
int randomPivot(int arr[], int low, int high) {
    srand(time(NULL));
    int random = low + rand() % (high - low);
    return random;
}

// H�m ph�n ho?ch (partition)
int partition(int arr[], int low, int high) {
    int pivotIndex = randomPivot(arr, low, high); // Ch?n v? tr� m?c ng?u nhi�n
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[high]); // ??a v? tr� m?c v? cu?i m?ng
    int i = low - 1; // V? tr� ph�n ho?ch cu?i c�ng

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivotValue) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // ??a v? tr� m?c v? ?�ng v? tr�
    return i + 1;
}

// H�m s?p x?p QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// H�m in m?ng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// H�m ch�nh
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

