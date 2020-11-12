#include <iostream>
#include <algorithm>

#include <vector>

using namespace std;


void PrintVector(vector<int>& nums) {
    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;
}


class Solution {
public:
    // https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
    //     The following algorithm generates the next permutation lexicographically after a given permutation. It changes the given permutation in-place.

    // Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
    // Find the largest index l greater than k such that a[k] < a[l].
    // Swap the value of a[k] with that of a[l].
    // Reverse the sequence from a[k + 1] up to and including the final element a[n].
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) return;

        int k = 0;
        for (int i=k, j=k+1; j<nums.size(); ++i, ++j) {
            if (nums[i] < nums[j]) {
                k = i;
            }
        }

        if (nums[k] >= nums[k+1]) {
            // reverse the nums
            reverse(nums, 0, nums.size()-1);
            return;
        }

        int l = k+1;
        for (int i=l; i<nums.size(); ++i) {
            if (nums.at(i) > nums.at(k)) {
                l = i;
            }
        }

        swap(nums[k], nums[l]);
        reverse(nums, k+1, nums.size()-1);
    }

    void reverse(vector<int>& nums, int begin, int end) {
        int swap_count = (end - begin+1) / 2;
        for (int i=0; i<swap_count; ++i) {
            swap(nums[begin+i], nums[end-i]);
        }
    }
};


int main() {
    vector<int> test_1 = vector<int>{1, 2, 3};
    vector<int> test_2 = vector<int>{3, 2, 1};
    vector<int> test_3 = vector<int>{1, 1, 5};
    vector<int> test_4 = vector<int>{1, 3, 2};
    vector<int> test_5 = vector<int>{2, 3, 1};

    vector<int> result;
    Solution s;
    s.nextPermutation(test_1);
    PrintVector(test_1);
    s.nextPermutation(test_2);
    PrintVector(test_2);
    s.nextPermutation(test_3);
    PrintVector(test_3);
    s.nextPermutation(test_4);
    PrintVector(test_4);
    s.nextPermutation(test_5);
    PrintVector(test_5);

    // next_permutation(test_4.begin(), test_4.end());
    // PrintVector(test_4);

    return 0;
}
