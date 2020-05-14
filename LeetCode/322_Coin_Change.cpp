//
// Created by 박혜원 on 2020/05/14.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp;
        dp.resize(amount + 1, amount + 1);
        dp[0] = 0;
        sort(coins.begin(), coins.end());

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] > i) break;
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << Solution().coinChange(coins, amount);
    return 0;
}