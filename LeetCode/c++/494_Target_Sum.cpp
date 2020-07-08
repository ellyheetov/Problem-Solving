//
// Created by 박혜원 on 2020/07/08.
//

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> check;

    int total_sum(vector<int> &nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        check.resize(sum * 2 + 1, 0);
        return sum;
    }

    void nextWay(int current, int next_index, vector<int> &nums) {
        if (next_index == nums.size() - 1) {
            check[current + nums[next_index]]++;
            check[current - nums[next_index]]++;
            return;
        }
        nextWay(current + nums[next_index], next_index + 1, nums);
        nextWay(current - nums[next_index], next_index + 1, nums);
    }

    int findTargetSumWays(vector<int> &nums, int S) {
        int sum = total_sum(nums);

        if (sum < S || (sum + S) % 2 > 0) return 0;

        nextWay(sum, 0, nums);

        return check[sum + S];
    }
};

int main() {
    vector<int> nums = {2, 1, 1};
    int target = 4;
    cout << Solution().findTargetSumWays(nums, target);
    return 0;
}