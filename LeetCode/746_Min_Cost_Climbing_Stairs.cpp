//
// Created by 박혜원 on 2020/05/07.
//

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        for (int i = 2; i < cost.size(); i++) {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }
        return min(cost[cost.size() - 1], cost[cost.size() - 2]);
    }
};

int main() {
    vector<int> num = {10, 15, 15, 30, 10};
    cout << Solution().minCostClimbingStairs(num);
    return 0;
}