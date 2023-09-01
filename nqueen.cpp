#include <iostream>

using namespace std;

bool isSafe(int board[][10], int row, int col, int N) {
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 1) {
            return false;
        }
    }
    for (int i = row+1; i < N; ++i) {
        if (board[i][col] == 1) {
            return false;
        }
    }
    
    for (int j = 0; j < col; ++j) {
        if (board[row][j] == 1) {
            return false;
        }
    }
    for (int j = col+1; j < N; ++j) {
        if (board[row][j] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}


void printBoard(int board[][10], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int totalSolutions = 0;

void solveNQueensUtil(int board[][10], int row, int N) {
    if (row == N) {
        printBoard(board, N);
        ++totalSolutions;
        return;
    }

    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;
            solveNQueensUtil(board, row + 1, N);
            board[row][col] = 0; // Backtrack
        }
    }
}

void solveNQueens(int N) {
    int board[10][10] = {0};
    totalSolutions = 0;

    solveNQueensUtil(board, 0, N);

    if (totalSolutions == 0) {
        cout << "No solutions exist." << endl;
    } else {
        cout << "Total solutions: " << totalSolutions << endl;
    }
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    solveNQueens(N);

    return 0;
}

    return 0;
}
