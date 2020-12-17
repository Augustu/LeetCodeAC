#include <iostream>

#include <vector>
#include <string>
#include <map>
#include <set>

#include "utils"

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> r = split(s, ' ');

        set<char> pset;
        set<string> rset;
        map<char, string> table;
        for (int i=0; i<pattern.size(); ++i) {
            pset.insert(pattern[i]);
            rset.insert(r[i]);

            map<char, string>::iterator iter = table.find(pattern[i]);
            if (iter == table.end()) {
                table.insert(map<char, string>::value_type(pattern[i], r[i]));
            } else {
                if (r[i] != iter->second) {
                    return false;
                }
            }
        }

        // for (auto iter = table.begin(); iter != table.end(); ++iter) {
        //     cout << iter->first << " " << iter->second << endl;
        // }

        // cout << pset.size() << " " << rset.size() << endl;
        if (pset.size() != rset.size() || pattern.size() != r.size()) {
            return false;
        }

        return true;
    }

    vector<string> split(string s, char d) {

        // clean string
        if (s.at(s.size()-1) == d) {
            s.pop_back();
        }

        vector<string> r;
        string ts;
        for (char c : s) {
            if (c != d) {
                ts.push_back(c);
            } else {
                r.push_back(ts);
                ts.erase();
            }
        }
        r.push_back(ts);

        return r;
    }
};

int main() {
    string test11 = "abba";
    string test12 = "dog cat cat dog";
    string test21 = "abba";
    string test22 = "dog cat cat fish";
    string test31 = "abba";
    string test32 = "dog dog dog dog";

    Solution s;
    bool result;
    result = s.wordPattern(test11, test12);
    cout << result << endl;
    result = s.wordPattern(test21, test22);
    cout << result << endl;
    result = s.wordPattern(test31, test32);
    cout << result << endl;

    return 0;
}