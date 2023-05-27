#include <iostream>
#include <vector>

using namespace std;

// Hàm c?ng hai ?a th?c
vector<int> addPolynomials(const vector<int>& A, const vector<int>& B) {
    int n = A.size();
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = A[i] + B[i];
    }
    return result;
}

// Hàm tr? hai ?a th?c
vector<int> subtractPolynomials(const vector<int>& A, const vector<int>& B) {
    int n = A.size();
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = A[i] - B[i];
    }
    return result;
}

// Hàm nhân ?a th?c
vector<int> multiplyPolynomials(const vector<int>& A, const vector<int>& B) {
    int n = A.size();
    if (n == 1) {
        vector<int> result(1);
        result[0] = A[0] * B[0];
        return result;
    }

    int mid = n / 2;

    vector<int> ALow(A.begin(), A.begin() + mid);
    vector<int> AHigh(A.begin() + mid, A.end());
    vector<int> BLow(B.begin(), B.begin() + mid);
    vector<int> BHigh(B.begin() + mid, B.end());

    vector<int> P1 = multiplyPolynomials(ALow, BLow);
    vector<int> P2 = multiplyPolynomials(AHigh, BHigh);
    vector<int> P3 = multiplyPolynomials(addPolynomials(ALow, AHigh), addPolynomials(BLow, BHigh));

    vector<int> result(n * 2 - 1);

    for (int i = 0; i < n; i++) {
        result[i] += P1[i];
        result[i + mid] += P3[i] - P1[i] - P2[i];
        result[i + n] += P2[i];
    }

    return result;
}

// Hàm in ?a th?c
void printPolynomial(const vector<int>& poly) {
    int n = poly.size();
    for (int i = 0; i < n; i++) {
        cout << poly[i];
        if (i != n - 1) {
            cout << "x^" << i << " + ";
        }
    }
    cout << endl;
}

int main() {
    // ?a th?c A: 1 + 2x + 3x^2
    vector<int> A = {1, 2, 3};

    // ?a th?c B: 4 + 5x + 6x^2
    vector<int> B = {4, 5, 6};

    vector<int> result = multiplyPolynomials(A, B);

    cout << "A = ";
    printPolynomial(A);

    cout << "B = ";
    printPolynomial(B);

    cout << "A * B = ";
    printPolynomial(result);

    return 0;
}
