#include <iostream>

#include <vector>

using namespace std;


void PrintVVI(vector<vector<int>>& vv) {
    for (vector<int> vec : vv) {
        for (int v : vec) {
            cout << v << " ";
        }
        cout << endl;
    }
}


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0) return vector<vector<int>>();

        vector<vector<int>> result;
        // add empty set
        result.emplace_back(vector<int>());

        // TODO using for (auto n : nums ) for vector
        for (int i=0; i<nums.size(); ++i) {
            int length = result.size();
            for (int j=0; j<length; ++j) {
                vector<int> new_vec(result[j]);
                new_vec.emplace_back(nums[i]);
                result.emplace_back(new_vec);
            }
        }

        return result;
    }
};


int main() {
    vector<int> test_1 = {1, 2, 3};

    vector<vector<int>> result;
    Solution s;
    result = s.subsets(test_1);
    PrintVVI(result);

    return 0;
}