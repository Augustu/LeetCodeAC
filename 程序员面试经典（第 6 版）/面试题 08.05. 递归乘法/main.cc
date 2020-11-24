#include <iostream>

#include <vector>

using namespace std;


/* time out
class Solution {
public:
    int multiply(int A, int B) {
        int result = 0;
        for (int i=0; i<A; ++i) {
            result += B;
        }
        return result;
    }
};
*/


/*
class Solution {
public:
    int multiply(int A, int B) {
        int smaller = A > B ? B : A;
        int bigger = A > B ? A : B;
        return minProductHelper(smaller, bigger);
    }

    int minProductHelper(int smaller, int bigger) {
        if (smaller == 0) return 0;
        if (smaller == 1) return bigger;

        int half = smaller >> 1;
        int side_1 = minProductHelper(half, bigger);
        int side_2 = side_1;
        if (smaller % 2 == 1) {
            side_2 = minProductHelper(smaller - half, bigger);
        }

        return side_1 + side_2;
    }
};
*/


class Solution {
public:
    int multiply(int A, int B) {
        int smaller = A > B ? B : A;
        int bigger = A > B ? A : B;
        return minProductHelper(smaller, bigger);
    }

    int minProductHelper(int smaller, int bigger) {
        if (smaller == 0) return 0;
        if (smaller == 1) return bigger;

        int half = smaller >> 1;
        int half_value = minProductHelper(half, bigger);

        if (smaller % 2 == 0) {
            return half_value + half_value;
        } else {
            return half_value + half_value + bigger;
        }
    }
};


int main() {
    int test_A = 3;
    int test_B = 4;

    int result = 0;
    Solution s;
    result = s.multiply(3, 4);
    cout << result << endl;

    return 0;
}
