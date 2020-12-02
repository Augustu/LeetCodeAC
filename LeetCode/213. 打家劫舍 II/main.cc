#include <iostream>

#include <vector>

using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        int length = nums.size();
        if ( length == 0 ) return 0;
        if ( length == 1 ) return nums[0];
        if ( length == 2 ) return max(nums[0], nums[1]);
        return max(robMax(nums, 0, length-1), robMax(nums, 1, length));
    }

    int robMax(vector<int>& nums, int start, int end) {
        int pre = 0;
        int cur = 0;

        for (int i=start; i<end; ++i) {
            int tmp = cur;
            cur = max(pre+nums[i], cur);
            pre = tmp;
        }

        return cur;
    }
};


int main() {
    return 0;
}
