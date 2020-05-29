//
// Created by 박혜원 on 2020/04/06.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<int> length_dp;
    int max_length = 1;

    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;

        length_dp.resize(nums.size(),1);

        for(int i =1; i< nums.size(); i++){
            for(int j =0; j < i; j++){
                if(nums[j] < nums[i]){
                    length_dp[i] = max(1+ length_dp[j],length_dp[i]);
                    max_length = max(max_length, length_dp[i]);
                }
            }
        }
        return max_length;
    }
};

int main(){

    vector<int> nums ={ 1,3,6,7,9,4,10,5,6};
    int ret = Solution().lengthOfLIS(nums);

    cout << ret;
}
