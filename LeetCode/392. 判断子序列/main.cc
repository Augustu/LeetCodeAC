#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty())
            return true;

        int current = 0;
        int sub_len = s.size() - 1;
        for (int i=0; i<t.size(); ++i) {
            if (s[current] == t[i]) {
                if (current == sub_len) {
                    return true;
                } else {
                    current++;
                }
            }
        }
        return false;
    }
};


int main() {
    string s1 = "abc";
    string t1 = "ahbgdc";

    string s2 = "axc";
    string t2 = "ahbgdc";

    Solution s;
    cout << s.isSubsequence(s1, t1) << endl;
    cout << s.isSubsequence(s2, t2) << endl;

    return 0;
}