//
// Created by 박혜원 on 2020/04/23.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> information;
    int amount = 0;

    void initial(vector<int> &nums) {
        information.resize(nums.size());
        information[0] = nums[0];
        information[1] = max(nums[0], nums[1]);
        information[2] = max(nums[1], nums[0] + nums[2]);
        amount = max({information[0], information[1], information[2]});
    }

    int rob(vector<int> &nums) {
        if (nums.size() == 0) return amount;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        initial(nums);
        for (int i = 3; i < nums.size(); i++) {
            information[i] = nums[i] + max(information[i - 2], information[i - 3]);
            amount = max(amount, information[i]);
        }
        return amount;
    }
};

int main() {
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << Solution().rob(nums);

    return 0;
}