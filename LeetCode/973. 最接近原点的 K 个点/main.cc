#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


void printResult(vector<vector<int>> result) {
    for (auto v : result) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}


/* run out of time
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> distance;
        vector<vector<int>> result;

        int i = 0;
        for (auto p : points) {
            distance.emplace_back(vector<int>{p[0]*p[0]+p[1]*p[1], i});
            i++;
        }

        sort(distance.begin(), distance.end(), compare);

        for (int i=0; i<K; ++i) {
            result.emplace_back(points.at(distance.at(i)[1]));
        }

        return result;
    }

    static bool compare(vector<int> a, vector<int> b) {
        if (a[0] != b[0]) return a[0] < b[0];
        if (a[1] != b[1]) return a[1] < b[1];
        return false;
    }
};
*/


/* AC one
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> distance;
        vector<vector<int>> result;

        int i = 0;
        for (auto p : points) {
            distance.push(vector<int>{p[0]*p[0]+p[1]*p[1], i});
            i++;
        }

        for (int i=0; i<K; ++i) {
            auto t = distance.top();
            result.emplace_back(points.at(t[1]));
            distance.pop();
        }

        return result;
    }
};
*/


// TODO add quick sort
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> distance;
        vector<vector<int>> result;

        return result;
    }

    void QuickSort() {}
};


int main() {
    vector<vector<int>> points_1 = { {1, 3}, {-2, 2} };
    int k_1 = 1;

    vector<vector<int>> points_2 = { {3, 3}, {5, -1}, {-2, 4} };
    int k_2 = 2;

    vector<vector<int>> result;
    Solution s;
    result = s.kClosest(points_1, k_1);
    printResult(result);
    result = s.kClosest(points_2, k_2);
    printResult(result);

    return 0;
}
