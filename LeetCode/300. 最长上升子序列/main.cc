#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len);
        dp[0] = 1;
        int maxval = 1;

        for (int i=1; i<len; ++i) {
            dp[i] = 1;
            for (int j=0; j<i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            maxval = max(dp[i], maxval);
        }

        return maxval;
    }
};

// TODO o(log(n)) method

int main() {
    vector<int> test_1 = {10,9,2,5,3,7,101,18};
    vector<int> test_2 = {0,1,0,3,2,3};
    vector<int> test_3 = {7,7,7,7,7,7,7};
    vector<int> test_4 = {1,3,6,7,9,4,10,5,6};

    Solution s;
    int result = 0;
    result = s.lengthOfLIS(test_1);
    cout << result << endl;
    result = s.lengthOfLIS(test_2);
    cout << result << endl;
    result = s.lengthOfLIS(test_3);
    cout << result << endl;
    result = s.lengthOfLIS(test_4);
    cout << result << endl;

    return 0;
}