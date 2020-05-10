//
// Created by 박혜원 on 2020/05/10.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string reverse_str = s;
        reverse(reverse_str.begin(), reverse_str.end());

        string new_string = s + '#' + reverse_str;

        vector<int> KMP(new_string.length(), 0);

        for (int i = 1; i < new_string.length(); i++) {
            int j = KMP[i - 1];
            while (j > 0 && new_string[i] != new_string[j])
                j = KMP[j - 1];
            if (new_string[i] == new_string[j])
                ++j;
            KMP[i] = j;
        }
        return reverse_str.substr(0, s.size() - KMP[new_string.length() - 1]) + s;
    }
};

int main() {
    string s = "abc";
    cout << Solution().shortestPalindrome(s);
    return 0;
}