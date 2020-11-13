#include <iostream>

#include <algorithm>
#include <vector>

using namespace std;


void PrintVector(vector<int> vec) {
    for (int v : vec) {
        cout << v << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<int> result;
        if (land.size() == 0) return result;
        if (land.at(0).size() == 0) return result;

        _rows = land.size();
        _cols = land.at(0).size();

        for (int i=0; i<_rows; ++i) {
            for (int j=0; j<_cols; ++j) {
                int size = computeSize(land, i, j);
                if (size != 0) {
                    result.emplace_back(size);
                }
            }
        }

        qsort(result.data(), result.size(), sizeof(int), compare);
        return result;
    }

    int computeSize(vector<vector<int>>& land, int row, int col) {
        if (row<0 || row>=_rows || col<0 || col>=_cols || land[row][col] != 0) {
            return 0;
        }

        int size = 1;
        land[row][col] = -1;

        for (int i=-1; i<=1; ++i) {
            for (int j=-1; j<=1; ++j) {
                size += computeSize(land, row+i, col+j);
            }
        }

        return size;
    }

    static int compare(const void* a, const void* b) {
        return *(int*)a - *(int*)b;
    }

private:
    int _rows;
    int _cols;
};


int main() {
    vector<vector<int>> test_1 = vector<vector<int>>{{0,2,1,0},
                                                     {0,1,0,1},
                                                     {1,1,0,1},
                                                     {0,1,0,1}};

    vector<int> result;
    Solution s;
    result = s.pondSizes(test_1);
    PrintVector(result);

    return 0;
}
