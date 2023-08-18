#include <iostream>
#include <vector>

bool isSafe(const std::vector<int>& board, int row, int col) {
    for (int prevRow = 0; prevRow < row; ++prevRow) {
        if (board[prevRow] == col ||           // Check same column
            abs(board[prevRow] - col) == row - prevRow) {  // Check diagonals
            return false;
        }
    }
    return true;
}

void solveNQueensUtil(std::vector<std::vector<int>>& solutions, std::vector<int>& board, int row, int n) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueensUtil(solutions, board, row + 1, n);
            board[row] = -1;  // Backtrack
        }
    }
}

std::vector<std::vector<int>> solveNQueens(int n) {
    std::vector<std::vector<int>> solutions;
    std::vector<int> board(n, -1);

    solveNQueensUtil(solutions, board, 0, n);

    return solutions;
}

void printBoard(const std::vector<int>& board) {
    int n = board.size();
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            if (board[row] == col) {
                std::cout << "Q ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    int n = 8; // Change 'n' to the desired board size

    std::vector<std::vector<int>> solutions = solveNQueens(n);

    for (const std::vector<int>& solution : solutions) {
        std::cout << "Solution:\n";
        printBoard(solution);
        std::cout << std::endl;
    }

    return 0;
}
