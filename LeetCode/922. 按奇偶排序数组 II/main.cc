#include <iostream>
#include <vector>

using namespace std;


void PrintVector(vector<int>& vec) {
    for (int v : vec) {
        cout << v << " ";
    }
    cout << endl;
}

/*
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int end = A.size();
        for (int i=0; i<A.size(); ++i) {
            if ( i%2 - A[i]%2 > 0 ) {
                for (int j=end-1; j>i; --j) {
                    if (j%2 - A[j]%2 < 0) {
                        swap(A[i], A[j]);
                        break;
                    }
                }
            }
            if ( i%2 - A[i]%2 < 0 ) {
                for (int j=end-1; j>i; --j) {
                    if (j%2 - A[j]%2 > 0) {
                        swap(A[i], A[j]);
                        break;
                    }
                }
            }
        }
        return A;
    }
};
*/


class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        for (int i=1,j=0,n=A.size(); i<n;) {
            if (A[i] & 1) {
                i+=2;
                continue;
            }
            swap(A[i], A[j]);
            j+=2;
        }
        return A;
    }
};


int main() {
    vector<int> test_1{4,2,5,7};
    vector<int> test_2{3,1,4,2};
    vector<int> test_3{1,4,4,3,0,3};

    vector<int> result;
    Solution s;
    result = s.sortArrayByParityII(test_1);
    PrintVector(result);
    result = s.sortArrayByParityII(test_2); // 2,1,4,3
    PrintVector(result);
    result = s.sortArrayByParityII(test_3); // 4,1,4,3,0,3
    PrintVector(result);
}
