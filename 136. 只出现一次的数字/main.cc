#include <iostream>

#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        map<int, int> statistics;
        for (int num : nums) {
            if (statistics.find(num) != statistics.end()) {
                statistics[num] += 1;
            } else {
                statistics[num] = 1;
            }
        }

        for (auto v : statistics) {
            if (v.second == 1) {
                return v.first;
            }
        }

        return 0;
    }
};

int main() {

    vector<int> nums1{2, 2, 1};
    vector<int> nums2{4, 1, 2, 1, 2};

    Solution s;

    cout << s.singleNumber(nums1) << endl;
    cout << s.singleNumber(nums2) << endl;

    return 0;
}