#include <iostream>

#include <vector>

using namespace std;


void PrintVS(vector<string> S) {
    for (string s : S) {
        cout << s << endl;
    }
}


/* method one
class Solution {
public:
    vector<string> permutation(string S) {
        if (S.empty()) return vector<string>{""};

        vector<string> result{""};
        for (char c : S) {
            int length = result.size();
            for (int i=0; i<length; ++i) {
                int pos = result.at(0).size();
                for (int j=0; j<=pos; ++j) {
                    string tmp = result[i].substr(0, j) + c + result[i].substr(j, pos);
                    result.emplace_back(tmp);
                }
            }
            result.erase(result.begin(), result.begin()+length);
        }

        return result;
    }
};
*/


// TODO try dfs
class Solution {
public:
    vector<string> permutation(string S) {
        if (S.empty()) return vector<string>{""};

        s_ = &S;
        length_ = S.size();

        vector<string> result;
        return result;
    }

    void dfs(int index, string path, vector<string>& result) {
        if (path.size() == length_) {
            result.emplace_back(path);
            return;
        }
    }

private:
    int length_;
    string* s_;
};


int main() {
    string test_1 = "abc";

    vector<string> result;
    Solution s;
    result = s.permutation(test_1);
    PrintVS(result);

    // string a = "abc";
    // string ab = a.insert(1, sizeof(char), 'd');
    // cout << a << " " << ab << endl;

    return 0;
}
