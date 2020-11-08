#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        if (rows == 0) {
            return false;
        }
        cols = board.at(0).size();
        if (cols == 0){
            return false;
        }
        if (word.empty()) {
            return false;
        }

        boardcpy = &board;
        wordcpy = &word;

        // https://stackoverflow.com/questions/37245333/this-cannot-be-used-in-a-constant-expression-error-c
        visited = new vector<vector<bool>>(rows, vector<bool>(cols));
        // for (auto v : *visited) {
        //     for (auto i : v) {
        //         cout << i << " ";
        //     }
        //     cout << endl;
        // }

        int pathLength = 0;
        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                if (hasPath(i, j, pathLength)) {
                    return true;
                }
            }
        }

        delete visited;
        return false;
    }

    bool hasPath(int row, int col, int pathLength) {
        if (pathLength == wordcpy->size()) {
            return true;
        }

        bool has = false;
        if (row >=0 && row < rows && col >=0 && col < cols
            && (*boardcpy)[row][col] == wordcpy->at(pathLength)
            && !(*visited)[row][col]) {
                pathLength++;
                (*visited)[row][col] = true;

                has = hasPath(row, col-1, pathLength)
                        || hasPath(row-1, col, pathLength)
                        || hasPath(row, col+1, pathLength)
                        || hasPath(row+1, col, pathLength);

                if (!has) {
                    pathLength--;
                    (*visited)[row][col] = false;
                }
            }

        return has;
    }

private:
    vector<vector<bool>> *visited;
    vector<vector<char>> *boardcpy;
    string *wordcpy;
    int cols = 0;
    int rows = 0;
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
