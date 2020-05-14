//
// Created by 박혜원 on 2020/05/14.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int i;
        for ( i = 0; i < nums.size(); i++) {
            if(nums[i] != i)
                return i;
        }
        return i;
    }
};


int main() {
    vector<int> nums = {0,2};
    cout << Solution().missingNumber(nums);
    return 0;
}