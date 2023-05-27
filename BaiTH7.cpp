#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<int>& board, int row, int col) {
    // Ki?m tra xem n?u c� con h?u tr�n c�ng m?t c?t ho?c tr�n ???ng ch�o ch�nh/ph?
    for (int i = 0; i < row; i++) {
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row) {
            return false;
        }
    }
    return true;
}

void solveNQueens(vector<vector<string>>& solutions, vector<int>& board, int row, int n) {
    if (row == n) {
        // T�m th?y m?t l?i gi?i, th�m b�n c? v�o danh s�ch l?i gi?i
        vector<string> solution;
        for (int i = 0; i < n; i++) {
            string rowString(n, '.');
            rowString[board[i]] = 'Q';
            solution.push_back(rowString);
        }
        solutions.push_back(solution);
    } else {
        // ??t c�c con h?u tr�n t?ng c?t trong h�ng hi?n t?i v� ki?m tra t�nh h?p l?
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col)) {
                board[row] = col;
                solveNQueens(solutions, board, row + 1, n);
            }
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solutions;
    vector<int> board(n, 0);
    solveNQueens(solutions, board, 0, n);
    return solutions;
}

void printSolutions(vector<vector<string>>& solutions) {
    int count = 1;
    for (auto solution : solutions) {
        cout << "Solution " << count << ":\n";
        for (auto row : solution) {
            cout << row << "\n";
        }
        cout << endl;
        count++;
    }
}

int main() {
    int n;
    cout << "Enter the number of queens (board size): ";
    cin >> n;

    vector<vector<string>> solutions = solveNQueens(n);
    cout << "Number of solutions: " << solutions.size() << "\n\n";
    printSolutions(solutions);

    return 0;
}

