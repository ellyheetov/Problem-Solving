//
// Created by 박혜원 on 2020/05/04.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        vector<int> inform;
        if (nums.size() == 0)
            return 0;
        int longest = 1;
        inform.resize(nums.size(), 1);

        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if(nums[i-1]== nums[i]) {
                inform[i] = inform[i - 1];
                continue;
            }
            if (nums[i - 1] + 1 == nums[i]) {
                inform[i] = inform[i - 1] + 1;
                longest = max(inform[i], longest);
            }
        }
        return longest;
    }
};

int main() {
    vector<int> nums = {100,4,200,1,2,3};
    cout << Solution().longestConsecutive(nums);
    return 0;
}