//
// Created by 박혜원 on 2020/04/13.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    void process(vector<int> &window, int start, int end){
        auto it = lower_bound(window.begin(), window.end(), end);
        window.insert(it,end);
        it = lower_bound(window.begin(), window.end(), start);
        window.erase(it);
    }
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        vector<int> window(nums.begin(), nums.begin() + k);
        sort(window.begin(), window.end());

        int answer_size = nums.size() - k +1 ;
        vector<double> answer(answer_size);

        for(int i =0; i< answer_size; i++)
        {
            if(k %2 ==0)
                answer[i] = (static_cast<double>(window[k/2-1]) + (double)window[k/2]) / 2;
            else
                answer [i] = window[k/2];
            if(i + k < nums.size()){
                process(window, nums[i], nums[i+k]);
            }
        }
        return answer;
    }
};

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<double> answer;
    int k = 3;
    answer = Solution().medianSlidingWindow(nums, k);
    for (auto i: answer) {
        cout << i << ' ';
    }
    return 0;
}