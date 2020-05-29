//
// Created by 박혜원 on 2020/04/08.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int pointer1 = 0;
        int pointer2 = numbers.size() - 1;

        while (pointer1 != pointer2) {
            if (numbers[pointer1] + numbers[pointer2] == target) {
                return vector<int>{pointer1 + 1, pointer2 + 1};
            }
            else {
                if (numbers[pointer1] + numbers[pointer2] < target)
                    pointer1++;
                else
                    pointer2--;
            }
        }
        return vector<int>{pointer1 + 1, pointer2 + 1};
    }
};

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> um;
        vector<int> ans;
        for(int i=0;i<numbers.size();i++){
            if(um.find(target-numbers[i])!=um.end()){
                ans.push_back(um[target-numbers[i]]);
                ans.push_back(i+1);
                break;
            }
            else{
                um[numbers[i]]=i+1;
            }
        }
        return ans;
    }
};
*/
