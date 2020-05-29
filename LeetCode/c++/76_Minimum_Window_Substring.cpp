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

    void initial_map( unordered_map<char, int> &pattern, string &t) {
        for (int i = 0; i < t.length(); i++) {
            if (!pattern.count(t[i])) pattern[t[i]] = 0;
            pattern[t[i]]++;
        }
    }

    bool is_contain(unordered_map<char, int> &pattern, char ch) {
        return pattern.count(ch);
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> pattern;
        int min_len = INT_MAX;

        initial_map(pattern,t);

        int left = 0, right = 0;
        int count = pattern.size(); //중복을 제외한 나머지 문자들의 갯수
        string answer = "";


        while (right < s.length()) {

            char endChar = s[right++];

            if (is_contain(pattern, endChar)) {
                if (--pattern[endChar] == 0) count--;
            }
            while (count == 0) {
                if (min_len > right - left) {
                    min_len = right - left;
                    answer = s.substr(left, min_len);
                }
                char startChar = s[left++];

                if (is_contain(pattern, startChar)) {
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