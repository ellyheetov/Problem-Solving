//
// Created by 박혜원 on 2020/05/04.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void process(vector<int> &window, int start, int end){
        auto it = lower_bound(window.begin(), window.end(), end);
        window.insert(it,end);
        it = lower_bound(window.begin(), window.end(), start);
        window.erase(it);
    }
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {

        vector<int> window(nums.begin(), nums.begin() + k);
        sort(window.begin(),window.end());

        int answer_size = nums.size() - k +1;
        vector<int> answer(answer_size);

        for(int i =0;i< answer_size; i++){
            answer[i] = window[k-1];
            if(i+k < nums.size()){
                process(window, nums[i],nums[i+k]);
            }
        }
        return answer;
    }
};

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> answer = Solution().maxSlidingWindow(nums,k);
    for(int i =0;i< answer.size();i++){
        cout << answer[i] << ' ';
    }
    return 0;
}