//
// Created by 박혜원 on 2020/07/02.
//

#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<int> st;

    for (int index = 0; index < arrangement.length(); index++) {
        if (arrangement[index] == '(') {
            st.push(1);
            continue;
        }
        st.pop();
        if (arrangement[index - 1] == '(') { //lazer
            answer += st.size();
            continue;
        }
        //막대의 끝
        answer++;
    }
    return answer;
}


int main() {
    cout << solution("(((())))");
    return 0;
}