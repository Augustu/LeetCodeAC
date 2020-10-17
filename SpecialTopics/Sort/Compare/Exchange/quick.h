#include <vector>

using namespace std;

class Quick {

public:
    vector<int> Sort(vector<int>& nums) {
        QuickSort(nums, 0, nums.size()-1);
        return nums;
    }

    // https://en.wikipedia.org/wiki/Quicksort
    void QuickSort(vector<int>& nums, int lo, int hi) {
        if ( lo < hi ) {
            int p = Partition(nums, lo, hi);
            QuickSort(nums, lo, p-1);
            QuickSort(nums, p+1, hi);
        }
    }

    int Partition(vector<int> &nums, int lo, int hi) {
        int pivot = nums[hi];
        int i = lo;
        for (int j=lo; j<hi; ++j) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[hi]);
        return i;
    }

    // void QuickSort(vector<int>& nums, int left, int right) {
    //     int base = nums[left];

    //     int i = left;
    //     int j = right;

    //     while (i < j) {
    //         while (j>i && nums[j] > base) {
    //             j--;
    //         }
    //         if ( i < j) {
    //             nums[i++] = nums[j];
    //         }
    //         while (i<j && nums[i] < base) {
    //             i++;
    //         }
    //         if ( i < j ) {
    //             nums[j--] = nums[i];
    //         }
    //     }

    //     if (i<=j) {
    //         nums[i] = base;
    //         cout << left << " " << i << " " << right << endl;
    //         QuickSort(nums, left, i-1);
    //         QuickSort(nums, i+1, right);
    //     }
    // }

};
