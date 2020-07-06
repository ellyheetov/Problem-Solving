//
// Created by 박혜원 on 2020/07/06.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int N) {
    long long answer = 0;

    vector<long> dp(N, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    answer = dp[N - 1] * 4 + dp[N - 2] * 2;
    return answer;
}

int main() {
    int n = 6;
    cout << solution(n);
    return 0;
}