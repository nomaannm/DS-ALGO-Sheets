#include<iostream>
#include<vector>
using namespace std;



bool isValid(vector<vector<char>>& board, int row, int col, char num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num ) return false;
    }

    int boxRowStart = (row / 3) * 3;
    int boxColStart = (col / 3) * 3;
    for (int i = boxRowStart; i < boxRowStart + 3; i++) {
        for (int j = boxColStart; j < boxColStart + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }


    return true;
}

bool solvingSudokuRecursionPolicy(vector<vector<char>>& board) {
    unsigned long long n = board.size();
    unsigned long long m = board[0].size();
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (board[row][col] == '.') {
                for (char num = '1'; num <= '9'; num++) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;

                        if (solvingSudokuRecursionPolicy(board)) {
                            return true;
                        }

                        board[row][col] = '.';
                    }

                }
                return false;

            }

        }
    }
    return true;
}

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.'},
        {'.', '7', '.'},
        {'.', '.', '2'}
    };

    if (solvingSudokuRecursionPolicy(board)) {
        for (auto row: board) {
            for (auto col: row) {
                cout << col << " ";
            }
            cout << endl;
        }
    }


}

