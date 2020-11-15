#include <iostream>
#include <string>
#include <deque>

using namespace std;


class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> dep;
        dep.push_back(num[0]);

        for (int i=1; i<num.size(); ++i) {
            auto ch = num[i];

            if (k != 0) {
                while (dep.size()) {
                    if (ch < dep.back()) {
                        dep.pop_back();
                        k--;
                        if (k == 0) break;
                    } else {
                        break;
                    }
                }
            }

            dep.push_back(num[i]);
        }

        while (k--) dep.pop_back();

        string result;
        bool zero = true;
        for (char c : dep) {
            if (zero && c == '0') continue;
            zero = false;
            result += c;
        }

        return result == "" ? "0" : result;
    }
};


int main() {
    return 0;
}