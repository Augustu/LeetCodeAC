#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int dp1 = 0;
    //     int dp2 = 0;

    //     for (int i=cost.size()-1; i>=0; --i) {
    //         int tmp = cost[i] + min(dp1, dp2);
    //         dp2 = dp1;
    //         dp1 = tmp;
    //     }

    //     return min(dp1, dp2);
    // }

    int minCostClimbingStairs(vector<int>& cost) {

        vector<int> dp(cost.size(), 0);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i=2; i<cost.size(); ++i) {
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }

        return min(dp[cost.size()-1], dp[cost.size()-2]);
    }
};


int main() {
    vector<int> test1 = vector<int>{10, 15, 20};
    vector<int> test2 = vector<int>{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    vector<int> test3 = vector<int>{0, 0, 0, 0};

    Solution s;
    cout << s.minCostClimbingStairs(test1) << endl;
    cout << s.minCostClimbingStairs(test2) << endl;
    cout << s.minCostClimbingStairs(test3) << endl;

    return 0;
}
