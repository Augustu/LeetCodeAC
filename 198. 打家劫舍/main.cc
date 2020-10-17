#include <iostream>
#include <vector>

// #include <algorithm>

using namespace std;

class Solution {
public:
    // int rob(vector<int>& nums) {
    //     if (nums.empty())
    //         return 0;

    //     if (nums.size() == 1) {
    //         return nums[0];
    //     }

    //     if (nums.size() == 2) {
    //         return max(nums[0], nums[1]);
    //     }

    //     vector<int> dp(nums.size(), 0);

    //     dp[0] = nums[0];
    //     dp[1] = max(nums[0], nums[1]);

    //     for (int i=2; i<nums.size(); ++i) {
    //         dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
    //     }

    //     return dp[nums.size()-1];
    // }

    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;

        if (nums.size() == 1) {
            return nums[0];
        }

        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        int a = nums[0];
        int b = max(nums[0], nums[1]);

        for (int i=2; i<nums.size(); ++i) {
            int c = max(a+nums[i], b);
            a = b;
            b = c;
        }

        return b;
    }
};

int main() {
    vector<int> test1 = vector<int>{1,2,3,1};
    vector<int> test2 = vector<int>{2,7,9,3,1};
    vector<int> test3 = vector<int>{2,1,1,2};

    Solution s;
    cout << s.rob(test1) << endl;
    cout << s.rob(test2) << endl;
    cout << s.rob(test3) << endl;

    return 0;
}