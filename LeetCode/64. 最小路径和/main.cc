#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> dp(row, vector<int>(col));
        dp[0][0] = grid[0][0];

        // init row
        for (int i=1; i<col; ++i) {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        // init col
        for (int i=1; i<row; ++i) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for (int i=1; i<row; ++i) {
            for (int j=1; j<col; ++j) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[row-1][col-1];
    }
};

int main() {
    vector<vector<int>> test_1 = {{1, 3, 1},
                                  {1, 5, 1},
                                  {4, 2, 1}};
    vector<vector<int>> test_2 = {{1, 2, 3},
                                  {4, 5, 6}};

    Solution s;
    int result;
    result = s.minPathSum(test_1);
    cout << result << endl;
    result = s.minPathSum(test_2);
    cout << result << endl;
    return 0;
}