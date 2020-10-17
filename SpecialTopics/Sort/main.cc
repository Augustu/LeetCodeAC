#include <iostream>
#include <vector>

// #include "Compare/Exchange/bubble.h"
// #include "Compare/Exchange/quick.h"
#include "Compare/Selection/simple.h"

#include <algorithm>

using namespace std;


// https://leetcode-cn.com/problems/sort-an-array/

int main() {
    vector<int> nums1 = { 5, 2, 3, 1 };
    vector<int> nums2 = { 5, 1, 1, 2, 0, 0 };

    vector<int> result;

    // // bubble
    // Bubble s;
    // result = s.Sort(nums1);

    // for (int r : result) {
    //     cout << r << " ";
    // }
    // cout << endl;

    // result = s.Sort(nums2);

    // for (int r : result) {
    //     cout << r << " ";
    // }
    // cout << endl;
    // // end bubble

    // // Quick Sort
    // Quick s;

    // result = s.Sort(nums1);
    // for (int r : result) {
    //     cout << r << " ";
    // }
    // cout << endl;

    // result = s.Sort(nums2);
    // for (int r : result) {
    //     cout << r << " ";
    // }
    // cout << endl;

    // Simple Selection
    Simple s;
    result = s.Sort(nums1);
    for (int r : result) {
        cout << r << " ";
    }
    cout << endl;

    result = s.Sort(nums2);
    for (int r : result) {
        cout << r << " ";
    }
    cout << endl;

}
