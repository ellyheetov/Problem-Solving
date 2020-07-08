//
// Created by 박혜원 on 2020/07/08.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int total_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            total_sum += nums[i];
        }
        if (total_sum % 2 != 0) return false;
        int part_sum = total_sum / 2;

        vector<bool> check(part_sum + 1, false);
        check[0] = true;

        for (int num : nums) {
            for (int i = part_sum; i >= num; i--) {
                check[i] = check[i] || check[i - num];
            }
        }
        return check[part_sum];
    }
};

int main() {
    vector<int> nums = {1, 5, 5, 11};
    bool answer = Solution().canPartition(nums);
    answer ? cout << "TRUE" : cout << "FALSE";
    return 0;
}