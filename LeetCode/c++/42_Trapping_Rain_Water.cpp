//
// Created by 박혜원 on 2020/04/08.
//

#include <iostream>
#include <climits>
#include <vector>

using namespace std;


class Solution {
public:
    int trap(vector<int> &height) {
        int area = 0;

        if(height.size() ==0)
            return 0;

        int left_index = 0;
        int left_max = height[left_index];
        int right_index = height.size() - 1;
        int right_max = height[right_index];

        while (left_index < right_index) {

            if (height[left_index] < left_max)
                area += left_max - height[left_index];
            if (height[right_index] < right_max)
                area += right_max - height[right_index];

            if (height[left_index] < height[right_index]) {
                left_index++;
                left_max = max(left_max, height[left_index]);
            } else {
                right_index--;
                right_max = max(right_max, height[right_index]);
            }
        }
        return area;
    }
};

int main() {
    vector<int> height = {4,2,3};
    cout << Solution().trap(height);

    return 0;
}