#include <iostream>
#include <vector>

using namespace std;


// class NumArray {
// public:
//     NumArray(vector<int>& nums) {

//         sums = new vector<int>(nums.size()+1, 0);

//         for (int i=0; i<nums.size(); ++i) {
//             (*sums)[i+1] = (*sums)[i] + nums[i];
//         }
//     }

//     ~NumArray() {
//         delete sums;
//     }

    
//     int sumRange(int i, int j) {
//         return (*sums)[j+1] - (*sums)[i];
//     }

// private:
//     vector<int> *sums;
// };


class NumArray {
public:
    NumArray(vector<int>& nums) {

        sums = new int[nums.size()+1];

        for (int i : nums) {
            *(sums+1) = *sums + i;
            sums++;
        }

        sums -= nums.size();
    }

    int sumRange(int i, int j) {
        return sums[j+1] - sums[i];
    }

private:
    int *sums;
};


int main() {
    vector<int> test1 = vector<int>{-2, 0, 3, -5, 2, -1};

    NumArray *n = new NumArray(test1);
    cout << n->sumRange(0, 2) << endl;
    cout << n->sumRange(2, 5) << endl;
    cout << n->sumRange(0, 5) << endl;

    return 0;
}