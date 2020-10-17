// P88

#include <iostream>
#include <vector>
#include <stack>

#include <stdlib.h>

using namespace std;


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        int rows = board.size();
        int cols = board[0].size();

        vector<bool> visited(rows*cols, false);

        int pathLength = 0;
        for (int row=0; row<rows; ++row) {
            for (int col=0; col<cols; ++col) {
                if (hasPathCore(board, rows, cols,
                    row, col, &word, pathLength, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool hasPathCore(vector<vector<char>>& matrix,
                     int rows, int cols, 
                     int row, int col,
                     const string* str,
                     int& pathLength,
                     vector<bool>& visited) {
        if (str->size() == pathLength) return true;

        bool hasPath = false;
        if (row >= 0 && row < rows &&
            col >= 0 && col < cols &&
            matrix[row][col] == str->at(pathLength)
            && !visited[row*cols + col]) {

            ++pathLength;
            visited[row*cols + col] = true;

            hasPath = hasPathCore(matrix, rows, cols,
                                  row, col-1,
                                  str, pathLength, visited)
                      || hasPathCore(matrix, rows, cols,
                                  row-1, col,
                                  str, pathLength, visited)
                      || hasPathCore(matrix, rows, cols,
                                  row, col+1,
                                  str, pathLength, visited)
                      || hasPathCore(matrix, rows, cols,
                                  row+1, col,
                                  str, pathLength, visited);

            if (!hasPath) {
                --pathLength;
                visited[row*cols + col] = false;
            }

        }

        return hasPath;
    }
};


int main() {
    vector<vector<char>> board_1 = {{'A', 'B', 'C', 'E'},
                                    {'S', 'F', 'C', 'S'},
                                    {'A', 'D', 'E', 'E'}};
    string word_1 = "ABCCED";

    vector<vector<char>> board_2 = {{'a', 'b'},
                                    {'c', 'd'}};
    string word_2 = "abcd";

    Solution s;
    cout << s.exist(board_1, word_1) << endl;
    cout << s.exist(board_2, word_2) << endl;

    return 0;
}
