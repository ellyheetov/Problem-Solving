//
// Created by 박혜원 on 2020/04/09.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        int answer = 0;
        sort(coins.begin(), coins.end());
        for (int i = coins.size() - 1; i >= 0; i--) {
            answer += amount / coins[i];
            amount = amount % coins[i];
        }
        return amount == 0 ? answer : -1;
    }
};

int main() {
    vector<int> coins = {186,419,83,408};
    int amount = 6249;


    cout << Solution().coinChange(coins, amount);
    return 0;
}