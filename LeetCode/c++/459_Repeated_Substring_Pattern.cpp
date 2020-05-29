//
// Created by 박혜원 on 2020/04/14.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = (int) s.length();
        string substr;

        for (int i = 1; i <= (len / 2); ++i) {
            substr = s.substr(0, len - i);
            if (len % i == 0 && substr == s.substr(i)) {  // rotation technique
                return true;
            }
        }
        return false;
    }
};

int main() {
    string s = "abababab";
    if (Solution().repeatedSubstringPattern(s))
        cout << "True";
    else
        cout << "False";

    return 0;
}