//
// Created by 박혜원 on 2020/05/03.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> color;

    void sortColors(vector<int> &nums) {
        int index = 0;
        color.resize(3, 0);
        for (int i = 0; i < nums.size(); i++) {
            color[nums[i]]++;
        }

        for (int i = 0; i < color.size(); i++) {
            while (color[i]-- > 0)
                nums[index++] = i;
        }
    }
};

int main() {
    vector<int> nums = {2,2,1};
    Solution().sortColors(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ' ';
    }
}
