#include <vector>

using namespace std;

class Bubble {

public:
    vector<int> Sort(vector<int>& nums) {

        for (int i=1; i<nums.size(); ++i) {
            for (int j=0; j<nums.size()-i; ++j) {
                if (nums[j] > nums[j+1]) {
                    swap(nums[j], nums[j+1]);
                }
            }
        }

        return nums;
    }

};