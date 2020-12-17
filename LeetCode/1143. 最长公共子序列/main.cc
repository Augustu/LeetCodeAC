#include <iostream>

#include <vector>

#include "utils"

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        vector<vector<int>> dp(len1, vector<int>(len2, 1));

        // init col
        for (int i=0; i<len1; ++i) {
            if (text1[i] != text2[0]) {
                dp[i][0] = 0;
            } else {
                break;
            }
        }
        // init row
        for (int j=0; j<len2; ++j) {
            if (text1[0] != text2[j]) {
                dp[0][j] = 0;
            } else {
                break;
            }
        }

        for (int i=1; i<len1; ++i) {
            for (int j=1; j<len2; ++j) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (text1[i] == text2[j]) {
                    dp[i][j] = max(dp[i-1][j-1]+1, dp[i][j]);
                }
                
            }
        }

        PrintVV(dp);

        return dp[len1-1][len2-1];
    }
};

int main() {
    string test11 = "abcde";
    string test12 = "ace";
    string test21 = "bl";
    string test22 = "yby";
    string test31 = "ezupkr";
    string test32 = "ubmrapg";
    string test41 = "aaa";
    string test42 = "aaaaa";

    Solution s;
    int result = 0;
    result = s.longestCommonSubsequence(test11, test12);
    cout << result << endl;
    result = s.longestCommonSubsequence(test21, test22);
    cout << result << endl;
    result = s.longestCommonSubsequence(test31, test32);
    cout << result << endl;
    result = s.longestCommonSubsequence(test41, test42);
    cout << result << endl;
    return 0;
}