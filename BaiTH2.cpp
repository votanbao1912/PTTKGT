#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

int main() {
    int n;
    std::cout << "Nhap kich thuoc cua ma tran: ";
    std::cin >> n;

    MatrixXd A(n, n);
    MatrixXd B(n, n);

    std::cout << "Nhap ma tran A: " << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> A(i, j);
        }
    }

    std::cout << "Nhap ma tran B: " << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> B(i, j);
        }
    }

    MatrixXd result = A * B;

    std::cout << "Ma tran ket qua: " << std::endl;
    std::cout << result << std::endl;

    return 0;
}
