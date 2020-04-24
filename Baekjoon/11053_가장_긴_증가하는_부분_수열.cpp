//
// Created by 박혜원 on 2020/03/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
vector<int> dp;

int answer;

void find_longest_subarray(int target) {
    for (int index = 0; index < target; ++index) {
        if (nums[index] < nums[target]) {
            dp[target] = max(dp[target], dp[index] + 1);
            if (answer < dp[target]) answer = dp[target];
        }
    }
    //answer = max(answer, dp[target]);
}

void solution() {
    for (int i = 0; i < nums.size(); i++) {
        find_longest_subarray(i);
    }
}

void input() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
        dp.push_back(1);
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    solution();

    cout << answer;

    return 0;
}