#include <iostream>
using namespace std;

// H�m t�nh gi� tr? ?a th?c theo ph??ng ph�p Horner
double hornerRecursive(double coeffs[], int n, double x) {
    // Tr??ng h?p c? s?: ?a th?c b?c 0
    if (n == 0) {
        return coeffs[0];
    }
    
    // T�nh gi� tr? ?a th?c c?a b?c n-1
    double prev = hornerRecursive(coeffs, n - 1, x);
    
    // �p d?ng c�ng th?c Horner ?? t�nh gi� tr? ?a th?c c?a b?c n
    return prev * x + coeffs[n];
}

int main() {
    // ?a th?c P(x) = 2x^3 - 3x^2 + 5x - 7
    double coeffs[] = {-7, 5, -3, 2};
    int degree = sizeof(coeffs) / sizeof(coeffs[0]) - 1;
    double x = 2.5;
    
    // T�nh gi� tr? ?a th?c
    double result = hornerRecursive(coeffs, degree, x);
    
    cout << "Gia tri da thuc tai x = " << x << " la " << result << endl;
    
    return 0;
}

