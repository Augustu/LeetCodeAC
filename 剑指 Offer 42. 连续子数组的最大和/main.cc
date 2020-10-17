#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int result = nums[0];
        int dp = nums[0];

        for (int i=1; i<nums.size(); ++i) {
            dp = nums[i] + max(dp, 0);
            result = max(result, dp);
        }

        return result;
    }
};


int main() {
    vector<int> test1 = vector<int>{-2,1,-3,4,-1,2,1,-5,4};
    vector<int> test2 = vector<int>{-2,-1};
    vector<int> test3 = vector<int>{-1,-2};

    Solution s;
    cout << s.maxSubArray(test1) << endl;
    cout << s.maxSubArray(test2) << endl;
    cout << s.maxSubArray(test3) << endl;

    return 0;
}
