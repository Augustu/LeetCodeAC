#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        int maxDist = max(r0, R - 1 - r0) + max(c0, C - 1 - c0);
        vector<vector<vector<int>>> bucket(maxDist + 1);

        for (int i=0; i<R; ++i) {
            for (int j=0; j<C; ++j) {
                int d = dist(i, j, r0, c0);
                vector<int> tmp = {i, j};
                bucket[d].push_back(move(tmp));
            }
        }

        vector<vector<int>> ret;
        for (int i=0; i<=maxDist; ++i) {
            for (vector<int> &it : bucket[i]) {
                ret.push_back(it);
            }
        }

        return ret;
    }

    int dist(int r1, int c1, int r2, int c2) {
        return abs(r1 - r2) + abs(c1 - c2);
    }
};


// TODO check method three
// https://leetcode-cn.com/problems/matrix-cells-in-distance-order/solution/ju-chi-shun-xu-pai-lie-ju-zhen-dan-yuan-ge-by-leet/

int main() {
    return 0;
}