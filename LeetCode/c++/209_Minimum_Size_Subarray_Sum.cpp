//
// Created by 박혜원 on 2020/04/09.
//

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {

        int start = 0, end = 0;
        int answer = INT_MAX;
        int cur_sum = 0;

        while (end < nums.size()) {
            cur_sum += nums[end++];
            while(cur_sum >= s){
                answer = min(answer,end - start);
                cur_sum -= nums[start++];
            }
        }
        return answer== INT_MAX ? 0 : answer;
    }
};

int main() {
    int s = 7;
    vector<int> nums = {2, 3, 1, 4};
    //vector<int> nums = {2,3,1,2,4,3};

    cout << Solution().minSubArrayLen(s, nums);
    return 0;
}