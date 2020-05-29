//
// Created by 박혜원 on 2020/05/05.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    void initial(unordered_map<char, int> &inform, string &s1) {
        for (int i = 0; i < s1.length(); i++) {
            if (inform.count(s1[i]) == 0) inform[s1[i]] = 0;
            ++inform[s1[i]];
        }
    }

    bool checkInclusion(string s1, string s2) {

        if (s2.length() < s1.length()) return false;

        unordered_map<char, int> inform;
        initial(inform, s1);

        int left = 0, right = 0;
        int len = 0;
        while (right < s2.length()) {
            char endChar = s2[right++];
            if (inform.count(endChar) != 0) {
                if (--inform[endChar] == 0)
                    len++;
            }
            while (len == inform.size()) {
                if (right - left == s1.length()) return true;
                char startChar = s2[left++];
                if (inform.count(startChar) != 0) {
                    if (++inform[startChar] > 0) {
                        len--;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    string s1 = "axae";
    string s2 = "aeax";

    Solution().checkInclusion(s1, s2) ? cout << "True" : cout << "False";
    return 0;
}