//
// Created by 박혜원 on 2020/05/10.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i =1;i< nums.size();i++){
            if(nums[i] == nums[i-1])
                return true;
        }
        return false;
    }
};

int main(){
    vector<int>nums = {1,2,3,1};
    Solution().containsDuplicate(nums) ? cout<< "True": cout << "False";

    return 0;
}


//using set

/*
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> check;
        for(int i =0;i< nums.size();i++){
            check.insert(nums[i]);
        }
        return check.size() != nums.size();
    }
};*/

//using map

/*
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> check;
        for(int i =0;i< nums.size();i++){
            if(check.count(nums[i]) == 0)
                check[nums[i]] = 0;
            else return true;
        }
        return false;
    }
};*/
