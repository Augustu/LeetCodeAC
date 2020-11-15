#include <vector>
#include <string>

using namespace std;


class OrderedStream {
public:
    OrderedStream(int n) {
        dict = new vector<string>(n+1);
        ptr = 1;
        num = n;
    }

    vector<string> insert(int id, string value) {
        vector<string> result;

        (*dict)[id] = value;
        if (id == ptr) {
            for (int i=id; i<=num; ++i) {
                if ((*dict)[i].empty()) {
                    ptr = i;
                    break;
                } else {
                    result.emplace_back((*dict)[i]);
                    ptr = i;
                }
            }
        }

        return result;
    }

private:
    vector<string>* dict;
    int ptr;
    int num;
};


int main() {
    return 0;
}
