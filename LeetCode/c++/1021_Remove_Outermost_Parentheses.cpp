//
// Created by 박혜원 on 2020/04/06.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        string answer;
        int opened = 0;

        for (char i : S) {
            if (i == '(' && opened++ > 0) answer += i;
            if (i == ')' && opened-- > 1) answer += i;
        }
        return answer;
    }
};

int main() {
    string str = "(()())(())";
    cout << Solution().removeOuterParentheses(str);
}