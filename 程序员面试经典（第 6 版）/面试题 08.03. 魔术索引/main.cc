#include <iostream>

#include <vector>

using namespace std;


class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        nums_ = &nums;
        return magicFast(0, nums.size()-1);
    }

    int magicFast(int start, int end) {
        if (end < start) return -1;

        int mid_index = (start + end) / 2;
        int mid_value = (*nums_)[mid_index];

        int left_index = min(mid_index-1, mid_value);
        int left = magicFast(start, left_index);
        if (left >= 0) return left;

        // mid check should after left check
        if (mid_value == mid_index) {
            return mid_index;
        }

        int right_index = max(mid_index+1, mid_value);
        int right = magicFast(right_index, end);
        return right;
    }

private:
    vector<int>* nums_;
};


int main() {
    vector<int> test_1 = {-99, -87, -69, -51, -40, -38, -31, -30, -18, -1, 10, 11, 41, 63, 71, 72, 72, 78, 86, 88};

    int result;
    Solution s;
    result = s.findMagicIndex(test_1);
    cout << result << endl;

    return 0;
}
