#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v){
            return u[1] < v[1];
        });

        int pos = points[0][1];
        int ans = 1;
        for (const vector<int>& balloon: points) {
            if (balloon[0] > pos) {
                pos = balloon[1];
                ++ans;
            }
        }
        return ans;
    }
};


int main() {
    vector<vector<int>> test_1 = {{10,16},{2,8},{1,6},{7,12}};
    vector<vector<int>> test_2 = {{1,2},{3,4},{5,6},{7,8}};
    vector<vector<int>> test_3 = {{1,2},{2,3},{3,4},{4,5}};
    vector<vector<int>> test_4 = {{1,2}};
    vector<vector<int>> test_5 = {{2,3},{2,3}};

    int result;
    Solution s;
    result = s.findMinArrowShots(test_1);
    cout << result << endl;

    return 0;
}
