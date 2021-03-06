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


/* method one, o(2^(r+c))
class Solution {
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0) {
            return vector<vector<int>>();
        }

        _obstacleGrid = &obstacleGrid;
        vector<vector<int>> result;

        if (getPath(obstacleGrid.size()-1, obstacleGrid[0].size()-1, result)) {
            return result;
        }

        return vector<vector<int>>();
    }

    bool getPath(int row, int col, vector<vector<int>>& result) {
        if (row < 0 || col < 0 || (*_obstacleGrid)[row][col]) {
            return false;
        }

        bool isAtOrigin = (row == 0) && (col == 0);

        if (isAtOrigin || getPath(row, col-1, result) || getPath(row-1, col, result)) {
            result.emplace_back(vector<int>{row, col});
            return true;
        }

        return false;
    }

private:
    vector<vector<int>>* _obstacleGrid;
};
*/


class Solution {
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0) {
            return vector<vector<int>>();
        }

        visited = new vector<vector<bool>>(obstacleGrid.size(), vector<bool>(obstacleGrid[0].size()));
        _obstacleGrid = &obstacleGrid;
        vector<vector<int>> result;
        if (getPath(obstacleGrid.size()-1, obstacleGrid[0].size()-1, result)) {
            return result;
        }

        return vector<vector<int>>();
    }

    bool getPath(int row, int col, vector<vector<int>>& result) {
        if (row < 0 || col < 0 || (*_obstacleGrid)[row][col] || (*visited)[row][col]) {
            return false;
        }

        bool isAtOrigin = (row == 0) && (col == 0);
        if (isAtOrigin || getPath(row-1, col, result) || getPath(row, col-1, result)) {
            result.emplace_back(vector<int>{row, col});
            (*visited)[row][col] = true;
            return true;
        }

        return false;
    }


private:
    vector<vector<int>>* _obstacleGrid;
    vector<vector<bool>>* visited;
};


// TODO using dp solve this


int main() {
    vector<vector<int>> test_1 = {{0,0,0}, {0,1,0}, {0,0,0}};

    vector<vector<int>> result;
    Solution s;
    result = s.pathWithObstacles(test_1);
    PrintVVI(result);
    
    return 0;
}
