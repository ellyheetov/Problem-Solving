//
// Created by 박혜원 on 2020/03/30.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string problem;

bool solution(){
    stack<char> parenthesis;

    for(int i =0; i< problem.length(); i++){
        if(problem[i] == ')' && !parenthesis.empty()) {
            if (parenthesis.top() == '(')
                parenthesis.pop();
            else
                return false;
        }
        else
            parenthesis.push(problem[i]);
    }
    if(parenthesis.empty()) return true;
    return false;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test_case;
    cin >> test_case;

    for(int i =0; i< test_case; i++){
        cin >> problem;
        if(solution()) cout<< "YES\n";
        else cout << "NO\n";
    }
    return 0;
}