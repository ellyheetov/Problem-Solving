//
// Created by 박혜원 on 2020/06/10.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp;
        dp.resize(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i-1]+1;
            for (int j = 2; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};

int main() {
    int n = 12;
    cout << Solution().numSquares(n);
    return 0;
}