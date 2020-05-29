//
// Created by 박혜원 on 2020/04/08.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int maxArea(vector<int>& height) {
        int start, end;
        int max_area =0;
        int cur_area;

        start = 0;
        end = height.size() -1;

        while( start!=end){
            cur_area = min(height[start],height[end])* (end-start);
            max_area = max(max_area, cur_area);
            //change_pointer
            if(height[start]< height[end])
                start++;
            else
                end--;
        }
        return max_area;
    }
};

int main(){

    vector<int> lines = {1,8,6,2,5,4,8,3,7};
    cout << Solution().maxArea(lines);

    return 0;

}