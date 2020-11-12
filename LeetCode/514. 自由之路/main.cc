#include <iostream>

#include <string>
#include <vector>

using namespace std;

void PrintVector(vector<vector<int>> vec) {
    for (vector<int>& v : vec) {
        for (int& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
}


class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();

        vector<int> pos[26];
        for (int i=0; i<n; ++i) {
            pos[ring[i] - 'a'].emplace_back(i);
        }

        vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, 0x3f3f3f3f));
        for (int& i : pos[key[0] - 'a']) {
            dp[0][i] = min(i, n-i) + 1;
        }

        for (int i=1; i<m; ++i) {
            for (int& j : pos[key[i] - 'a']) {
                for (int& k : pos[key[i-1] - 'a']) {
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + min(abs(j-k), n-abs(j-k))+1);
                }
            }
        }

        int min = dp[m-1][0];
        for (int i : dp[m-1]) {
            if (min > i) {
                min = i;
            }
        }

        return min;
    }
};


int main() {
    string ring_1 = "godding";
    string key_1 = "gd";

    int result;
    Solution s;
    result = s.findRotateSteps(ring_1, key_1);
    cout << result << endl;

    return 0;
}


