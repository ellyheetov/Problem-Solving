//
// Created by 박혜원 on 2020/04/13.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(right == 0 || nums[right -1] != target)
            return {-1,-1};
        else
            return {left,right - 1};
    }
};
int main() {

    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 5;

    vector<int> answer = Solution().searchRange(nums, target);
    for (auto it : answer)
        cout << it << ' ';

    return 0;
}