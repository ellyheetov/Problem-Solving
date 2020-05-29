//
// Created by 박혜원 on 2020/04/09.
//

#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0;
        int len = 0;
        set<char> dict;

        while (end < s.length()) {
            if (!dict.count(s[end])){ // not exist
                dict.insert(s[end++]);
            }
            else{
                dict.erase(s[start++]);
            }
            len = max(len, end - start);
        }
        return len;
    }
};


int main() {
    string str = "pwwkew";
    cout << Solution().lengthOfLongestSubstring(str);
    return 0;
}