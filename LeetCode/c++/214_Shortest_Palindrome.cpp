//
// Created by 박혜원 on 2020/05/10.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s){
        int i = 0;
        for (int j = s.size() - 1; j >= 0; j--) {
            if (s[i] == s[j])
                i++;
        }
        if (i == s.size())
            return s;
        string remain_rev = s.substr(i, s.size());
        reverse(remain_rev.begin(), remain_rev.end());
        return remain_rev + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }
};

int main() {
    string s = "abbc";
    cout << Solution().shortestPalindrome(s);
    return 0;
}