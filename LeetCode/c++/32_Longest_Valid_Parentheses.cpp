//
// Created by 박혜원 on 2020/05/03.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0;
        stack<int> st;
        st.push(-1);

        for(int index = 0; index < s.length(); index++){
            if(s[index] == '(') {
                st.push(index);
                continue;
            }
            //s[index] == ')'
            st.pop();
            if(st.empty()) {
                st.push(index);
                continue;
            }
            max_len = max(max_len, index - st.top());
        }
        return max_len;
    }
};

int main() {
    string s = "()(())";
    cout << Solution().longestValidParentheses(s);
    return 0;
}