//
// Created by 박혜원 on 2020/04/30.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i])
                return nums[i];
        }
        return 0;
    }
};

int main() {
    vector<int> nums = {3, 1, 3, 4, 2};
    cout << Solution().findDuplicate(nums);
    return 0;
}