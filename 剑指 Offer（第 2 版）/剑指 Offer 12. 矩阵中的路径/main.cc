#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        return true;
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
