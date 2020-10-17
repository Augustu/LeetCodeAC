#include <vector>

using namespace std;

class Simple {

public:
    vector<int> Sort(vector<int>& nums) {
        if (nums.empty()) {
            return nums;
        }

        for (int i=0; i<nums.size(); ++i) {
            int min = nums[i];
            int min_index = i;
            for (int j=i; j<nums.size(); ++j) {
                if (min > nums[j]) {
                    min = nums[j];
                    min_index = j;
                }
            }
            swap(nums[i], nums[min_index]);
        }

        return nums;
    }
};