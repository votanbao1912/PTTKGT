#include <iostream>
#include <cstring>
using namespace std;

// Hàm tìm chu?i chung dài nh?t
void longestCommonSubstring(string str1, string str2) {
    int len1 = str1.length();
    int len2 = str2.length();

    int longest = 0; // ?? dài c?a chu?i chung dài nh?t
    int endIdx = 0; // Ch? s? k?t thúc c?a chu?i chung dài nh?t trong str1

    int** dp = new int*[len1 + 1]; // T?o m?ng 2D ?? l?u các giá tr? trung gian
    for (int i = 0; i <= len1; i++) {
        dp[i] = new int[len2 + 1];
        memset(dp[i], 0, sizeof(int) * (len2 + 1));
    }

    // Duy?t qua t?ng ký t? trong str1 và str2 ?? tìm chu?i chung
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > longest) {
                    longest = dp[i][j];
                    endIdx = i - 1;
                }
            }
        }
    }

    // In ra chu?i chung dài nh?t
    if (longest > 0) {
        cout << "Chuoi chung dai nhat: ";
        for (int i = endIdx - longest + 1; i <= endIdx; i++) {
            cout << str1[i];
        }
        cout << endl;
    } else {
        cout << "Khong co chuoi chung" << endl;
    }

    // Gi?i phóng b? nh?
    for (int i = 0; i <= len1; i++) {
        delete[] dp[i];
    }
    delete[] dp;
}

int main() {
    string str1, str2;
    cout << "Nhap chuoi 1: ";
    getline(cin, str1);
    cout << "Nhap chuoi 2: ";
    getline(cin, str2);

    longestCommonSubstring(str1, str2);

    return 0;
}

