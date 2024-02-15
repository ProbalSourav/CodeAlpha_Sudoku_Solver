#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<char>>& board, int row, int col, int number) {
    // Check column
    for (int i = 0; i < board.size(); ++i) {
        if (board[i][col] == (char)(number + '0')) {
            return false;
        }
    }

    // Check row
    for (int j = 0; j < board.size(); ++j) {
        if (board[row][j] == (char)(number + '0')) {
            return false;
        }
    }

    // Check grid
    int sr = 3 * (row / 3);
    int sc = 3 * (col / 3);

    for (int i = sr; i < sr + 3; ++i) {
        for (int j = sc; j < sc + 3; ++j) {
            if (board[i][j] == (char)(number + '0')) {
                return false;
            }
        }
    }

    return true;
}

bool helper(vector<vector<char>>& board, int row, int col) {
    if (row == board.size()) {
        return true;
    }

    int nrow = 0;
    int ncol = 0;

    if (col == board.size() - 1) {
        nrow = row + 1;
        ncol = 0;
    } else {
        nrow = row;
        ncol = col + 1;
    }

    if (board[row][col] != '.') {
        if (helper(board, nrow, ncol)) {
            return true;
        }
    } else {
        // Fill the place
        for (int i = 1; i <= 9; ++i) {
            if (isSafe(board, row, col, i)) {
                board[row][col] = (char)(i + '0');
                if (helper(board, nrow, ncol)) {
                    return true;
                } else {
                    board[row][col] = '.';
                }
            }
        }
    }

    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    helper(board, 0, 0);
}

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    solveSudoku(board);

    // Print the solved Sudoku board
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
