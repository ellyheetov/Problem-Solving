//
// Created by 박혜원 on 2020/04/30.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<bool> visit;

    int findDuplicate(vector<int> &nums) {

        visit.resize(nums.size(), false);
        sort(nums.begin(), nums.end());

        for (int index = 0; index < nums.size(); index++) {
            if(visit[index])
                continue;
            while (index < nums.size()) {
                if (visit[index])
                    return nums[index];
                visit[index] = true;
                index = nums[nums[index]];
            }
        }
        return 0;
    }
};

int main() {
    vector<int> nums = {1,3,4,2,2};
    cout << Solution().findDuplicate(nums);
    return 0;
}