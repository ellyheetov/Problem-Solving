//
// Created by 박혜원 on 2020/04/01.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:

    int findLengthOfLCIS(vector<int>& nums) {

        int max_length=1;
        int cur_max=1;

        if(nums.empty())
            return 0;

        for(int i = 1; i< nums.size();i++){
            if(nums[i] > nums[i-1]) {
                cur_max++;
                if(max_length < cur_max)
                    max_length = cur_max;
            }
            else
                cur_max= 1;
        }
        return max_length;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().findLengthOfLCIS(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}