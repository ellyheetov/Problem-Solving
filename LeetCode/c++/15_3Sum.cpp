//
// Created by 박혜원 on 2020/07/08.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> answer;

        sort(nums.begin(), nums.end());
        int len = nums.size();

        for (int i = 0; i < len - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 중복을 방지
            int left = i + 1;
            int right = len - 1;
            while (left < right) {
                int sum = nums[left] + nums[i] + nums[right];

                if (sum == 0) {
                    answer.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    while (left < right && nums[left - 1] == nums[left]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                }
            }
        }
        return answer;
    }
};

int main() {
    vector<int> nums = {-2, 0, 0, 2, 2};
    vector<vector<int>> answer = Solution().threeSum(nums);

    return 0;
}

