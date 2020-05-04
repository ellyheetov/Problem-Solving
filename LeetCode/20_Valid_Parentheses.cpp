//
// Created by 박혜원 on 2020/05/04.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i =0;i< s.length();i++){
            if(s[i] == '(' || s[i] == '{' || s[i]=='[') {
                st.push(s[i]);
                continue;
            }
            if(st.empty())
                return false;
            if(s[i] == ')' && st.top() == '(')
                st.pop();
            else if(s[i] == '}' && st.top() == '{')
                st.pop();
            else if(s[i] == ']' && st.top() == '[')
                st.pop();
            else
                return false;
        }
        return st.empty();
    }
};

int main(){
    string s = "]";
//    cin>>s;
    Solution().isValid(s) ? cout << "true" : cout << "false";
}