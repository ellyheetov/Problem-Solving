//
// Created by 박혜원 on 2020/04/14.
//

//
// Created by 박혜원 on 2020/04/10.
//

#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

class Solution {
public:

    string minWindow(string s, string t) {
        string answer = "";
        int min = INT_MAX;

        unordered_map<char, int> pattern;

        //map_initialization
        for (int i = 0; i < t.size(); i++) {
            if (!pattern.count(t[i])) pattern[t[i]] = 0;
            pattern[t[i]]++;
        }
        int left = 0, right = 0;
        int count = pattern.size();

        while (right < s.length()) {
            char endChar = s[right++];

            if (pattern.count(endChar) == 0) { // not contain
                continue;
            }
            //contain
            if (--pattern[endChar] == 0)
                count--;

            //all find
            while (count == 0) {

                if (min > right - left) {
                    min = right - left;
                    answer = s.substr(left, min);
                }
                char startChar = s[left++];
                if (pattern.count(startChar)) { //contain
                    if (++pattern[startChar] > 0) count++;
                }
            }
        }
        return answer;
    }
};

int main() {
    string s = "ACBA";
    string t = "AA";

    cout << Solution().minWindow(s, t);
    return 0;
}