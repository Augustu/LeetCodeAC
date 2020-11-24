#include <iostream>

using namespace std;


// method one, timeout :(
// class Solution {
// public:
//     int waysToStep(int n) {
//         if (n<0) {
//             return 0;
//         } else if (n == 0) {
//             return 1;
//         } else {
//             return waysToStep(n-1) + waysToStep(n-2) + waysToStep(n-3);
//         }
//     }
// };


// method two, AC, but slow and big
// class Solution {
// public:
//     int waysToStep(int n) {
//         return int(waysToStepHelper(n));
//     }

//     unsigned long long waysToStepHelper(int n) {
//         if (n < 0) {
//             return 0;
//         } else if (n == 0) {
//             return 1;
//         } else if (cache[n] > 0) {
//             return cache[n];
//         } else {
//             cache[n] = (waysToStepHelper(n-1)
//                         + waysToStepHelper(n-2)
//                         + waysToStepHelper(n-3))
//                         % 1000000007;
//             return cache[n];
//         }
//     }

// private:
//     unsigned long long cache[1000000];
// };


// /*
// method three, ref https://leetcode-cn.com/problems/three-steps-problem-lcci/solution/mei-ri-suan-fa-day-80-suo-you-ren-du-hui-zuo-de-ru/
#include <vector>
// shorten type name
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
const ll p = 1e9+7;


void PrintVVL(vvl& matrix) {
    for (vl vec : matrix) {
        for (ll v : vec) {
            cout << v << " ";
        }
        cout << endl;
    }
}


/* nice algorithm
class Solution {
public:
    int waysToStep(int n) {
        vl f = {1, 2, 4};
        if (n <= 3) return f[n-1];

        vvl A = {{0,0,1}, {1,0,1}, {0,1,1}};
        vvl B = mat_pow(A, n-3);

        ll res = 0;
        for (int i=0; i<3; ++i) {
            res += f[i] * B[i][2];
            res %= p;
        }

        return res;
    }

    vvl mat_mul(vvl& A, vvl& B) {
        int a_row = A.size();
        int b_row = B.size();
        int b_col = B[0].size();

        vvl C(a_row, vl(b_col, 0));
        for (int i=0; i<a_row; ++i) {
            for (int j=0; j<b_col; ++j) {
                for (int k=0; k<b_row; ++k) {
                    C[i][j] += A[i][k] * B[k][j];
                    C[i][j] %= p;
                }
            }
        }

        return C;
    }

    // TODO understand this
    vvl mat_pow(vvl& A, int n) {
        int m = A.size();
        vvl B(m, vl(m, 0));
        for (int i = 0; i < m; ++i) B[i][i] = 1;
        while (n > 0) {
            if (n&1) B = mat_mul(B, A);
            A = mat_mul(A, A);
            n >>= 1;
        }
        return B;
    }
};
*/


class Solution {
public:
    int waysToStep(int n) {
        if (n < 4) {
            return n == 3 ? 4 : n;
        }

        int a = 1;
        int b = 2;
        int c = 4;

        int result  = 0;
        n -= 3;
        while (n--) {
            result = (a + b) % 1000000007 + c;
            result %= 1000000007;
            a = b;
            b = c;
            c = result;
        }

        return result;
    }
};


int main() {
    int result;

    Solution s;
    result = s.waysToStep(61);
    cout << result << endl;
    // result = s.waysToStep(61);
    // cout << result << endl;

    // vvl A = {{0,0,1}, {1,0,1}, {0,1,1}};
    // cout << "A" << endl;
    // PrintVVL(A);
    // vvl B = s.mat_mul(A, A);
    // cout << "B" << endl;
    // PrintVVL(B);

    return 0;
}
