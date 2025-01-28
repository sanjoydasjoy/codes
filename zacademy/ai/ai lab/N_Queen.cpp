// find all the possible solutions of N Queen problem

#include <iostream>
#include <vector>
using namespace std;

void printSolution(const vector<int>& board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void solveNQueens(int N, vector<int>& board, int row, int& solutionCount) {
    if (row == N) { //all rows have been filled with queens
        solutionCount++;
        if (solutionCount <= 10) { 
            cout << "Solution " << solutionCount << ":\n";
            printSolution(board, N);
        }
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col; // the column where the queen is placed for the current row.
            solveNQueens(N, board, row + 1, solutionCount); 
            board[row] = -1;  // the queen is removed and the loop continues to try other column positions for the current row.

            // different column for the same row.

        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> board(N, -1);
    int solutionCount = 0;

    solveNQueens(N, board, 0, solutionCount);

    cout << "Total solutions: " << solutionCount << endl;
    return 0;
}
