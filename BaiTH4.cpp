#include <iostream>

// Hàm hoán ??i giá tr? c?a hai ph?n t?
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Hàm chia m?ng và ??t ph?n t? pivot vào ?úng v? trí
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Ch?n pivot là ph?n t? cu?i cùng
    int i = (low - 1); // Ch? s? c?a ph?n t? nh? h?n pivot

    for (int j = low; j <= high - 1; j++) {
        // N?u ph?n t? hi?n t?i nh? h?n ho?c b?ng pivot
        if (arr[j] <= pivot) {
            i++; // T?ng ch? s? c?a ph?n t? nh? h?n pivot
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Hàm s?p x?p m?ng b?ng thu?t toán QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Tìm ph?n t? pivot ?úng v? trí
        int pi = partition(arr, low, high);

        // S?p x?p các ph?n t? n?m bên trái và bên ph?i pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Hàm in m?ng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Mang ban dau: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    std::cout << "Mang sau khi sap xep: ";
    printArray(arr, n);

    return 0;
}#include <iostream>

// Hàm hoán ??i giá tr? c?a hai ph?n t?
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Hàm chia m?ng và ??t ph?n t? pivot vào ?úng v? trí
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Ch?n pivot là ph?n t? cu?i cùng
    int i = (low - 1); // Ch? s? c?a ph?n t? nh? h?n pivot

    for (int j = low; j <= high - 1; j++) {
        // N?u ph?n t? hi?n t?i nh? h?n ho?c b?ng pivot
        if (arr[j] <= pivot) {
            i++; // T?ng ch? s? c?a ph?n t? nh? h?n pivot
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Hàm s?p x?p m?ng b?ng thu?t toán QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Tìm ph?n t? pivot ?úng v? trí
        int pi = partition(arr, low, high);

        // S?p x?p các ph?n t? n?m bên trái và bên ph?i pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Hàm in m?ng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Mang ban dau: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    std::cout << "Mang sau khi sap xep: ";
    printArray(arr, n);

    return 0;
}
