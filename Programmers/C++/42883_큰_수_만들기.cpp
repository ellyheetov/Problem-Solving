//
// Created by 박혜원 on 2020/07/03.
//

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> st;
    int size = number.length() - k;

    for(int i =0;i< number.length(); i++){
        char num = number[i];
        while(!st.empty() && k >0 ){
            if(st.top() < num){
                st.pop();
                k--;
            } else break;
        }
        st.push(num);
    }
    while(size != st.size())  st.pop();

    while(!st.empty()){
        answer += st.top();
        st.pop();
    }
    reverse(answer.begin(),answer.end());
    return answer;
}

int main() {
    string number = "4177252841";
    int k = 4;
    cout << solution(number, k);
    return 0;
}