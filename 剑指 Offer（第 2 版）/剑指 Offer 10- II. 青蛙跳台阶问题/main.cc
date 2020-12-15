#include <iostream>

using namespace std;

#define MOD int(1e9+7)

class Solution {
public:
    int numWays(int n) {
        if (n == 0) return 1;
        if (n < 3) return n;

        int a = 1, b = 2, result = 0;
        n -= 2; // 2 conditions checked in if

        while (n--) {
            result = (a + b) % MOD;
            a = b;
            b = result;
        }

        return result;
    }
};

int main() {
    int test_1 = 2;
    int test_2 = 7;
    int test_3 = 0;

    Solution s;
    int result = 0;
    result = s.numWays(test_1);
    cout << result << endl;
    result = s.numWays(test_2);
    cout << result << endl;
    result = s.numWays(test_3);
    cout << result << endl;
    return 0;
}