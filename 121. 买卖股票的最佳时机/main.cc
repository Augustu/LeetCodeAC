#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // int maxProfit(vector<int>& prices) {
    //     int max = 0;
    //     int tmp_prices = 0;
    //     for (int i=0; i<prices.size(); ++i) {
    //         for (int j=0; j<i; ++j) {
    //             tmp_prices = prices[i] - prices[j];
    //             max = max > tmp_prices ? max : tmp_prices;
    //         }
    //     }
    //     return max;
    // }

    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int *min_price = &prices[0];
        int profit = 0;
        int tmp_profit = 0;

        for (int i=1; i<prices.size(); ++i) {
            if (*min_price > prices[i]) {
                min_price = &prices[i];
            }
            tmp_profit = prices[i] - *min_price;
            if (tmp_profit > profit) {
                profit = tmp_profit;
            }
        }

        return profit;
    }
};

int main() {
    vector<int> test1 = vector<int>{ 7, 1, 5, 3, 6, 4 };
    vector<int> test2 = vector<int>{ 7, 6, 4, 3, 1 };

    Solution s;
    cout << s.maxProfit(test1) << endl;
    cout << s.maxProfit(test2) << endl;

    return 0;
}