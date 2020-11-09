#include <iostream>
#include <vector>

using namespace std;

void PrintVector(vector<int> nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int partition(vector<int> &nums, int left, int right) {
    int value = nums[left];
    int j = left;
    for (int i=left+1; i<=right; ++i) {
        if (nums[i] < value) {
            j++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[left], nums[j]);
    return j;
}

void quickSortRecursion(vector<int> &nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int part = partition(nums, left, right);
    quickSortRecursion(nums, left, part);
    quickSortRecursion(nums, part+1, right);
}

void QuickSort(vector<int> &nums) {
    quickSortRecursion(nums, 0, nums.size()-1);
}

int main() {
    vector<int> test_1 = {2, 5, 1, 9, 4, 0, 3};
    QuickSort(test_1);
    PrintVector(test_1);
    return 0;
}
