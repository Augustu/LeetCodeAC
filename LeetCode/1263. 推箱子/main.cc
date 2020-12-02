#include <iostream>

#include <vector>

using namespace std;


void PrintVVI(vector<vector<int>>& vec) {
    for (vector<int> v : vec) {
        for (int n : v) {
            cout << n << " ";
        }
        cout << endl;
    }
}

void PrintVVB(vector<vector<bool>>& vec) {
    for (vector<bool> v : vec) {
        for (bool n : v) {
            cout << n << " ";
        }
        cout << endl;
    }
}


class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {

    }
};


int main() {
    vector<vector<char>> test_1 = {{'#','#','#','#','#','#'},
                                   {'#','T','#','#','#','#'},
                                   {'#','.','.','B','.','#'},
                                   {'#','.','#','#','.','#'},
                                   {'#','.','.','.','S','#'},
                                   {'#','#','#','#','#','#'}};

    vector<vector<char>> test_2 = {{'#','#','#','#','#','#'},
                                   {'#','T','.','.','#','#'},
                                   {'#','.','#','B','.','#'},
                                   {'#','.','.','.','.','#'},
                                   {'#','.','.','.','S','#'},
                                   {'#','#','#','#','#','#'}};

    Solution s;
    int result;
    // result = s.minPushBox(test_1);
    // cout << result << endl;
    result = s.minPushBox(test_2);
    cout << result << endl;

    return 0;
}
