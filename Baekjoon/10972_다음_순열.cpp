//
// Created by 박혜원 on 2020/03/27.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int input;
    vector<int> nums;

    cin >> input;
    nums.resize(input);
    for (int i = 0; i < input; i++) {
        int x;
        cin >> x;
        nums[i] = x;
    }
    if (next_permutation(nums.begin(), nums.end())) {
        for (auto it : nums)
            cout << it << " ";
        return 0;
    }
    cout << -1;
    return 0;
}