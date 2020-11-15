#include <vector>
#include <string>

using namespace std;


// TODO fix this
// https://leetcode-cn.com/contest/weekly-contest-215/problems/minimum-operations-to-reduce-x-to-zero/
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int step;
        return minOperations(nums, 0, nums.size()-1, x, step);
    }

    int minOperations(vector<int>& nums, int start, int end, int x, int step) {
        if (x <= 0) return -1;
        if (start > end) return -1;

        int middle = x;
        if (start == end) {
            if (middle - nums[start] == 0) {
                return step++;
            }
            return -1;
        }

        int left = minOperations(nums, start+1, end, x-nums[start], step);
        if (left > 0) {
            left += step;
        }

        int right = minOperations(nums, start, end-1, x-nums[end], step);
        if (right > 0) {
            right += step;
        }

        if (left > 0 && right > 0) {
            return min(left, right);
        }

        if (left < 0 && right > 0) {
            return right;
        }

        if (left > 0 && right < 0) {
            return left;
        }

        return -1;
    }
};


int main() {
    return 0;
}
