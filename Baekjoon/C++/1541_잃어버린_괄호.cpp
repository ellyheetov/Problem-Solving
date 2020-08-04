//
// Created by 박혜원 on 2020/04/06.
//

#include <iostream>
#include <stack>
#include <vector>

#define MINUS -1
#define PLUS 1

using namespace std;

vector<int> sign;
vector<int> nums;

void preprocess(string &text){
    int cur_num = 0;

    for (int i = 0; i < text.length(); i++) {

        if (text[i] == '+' || text[i] == '-') {
            if(text[i] == '+'){
                sign.push_back(1);
            }else if(text[i] == '-'){
                sign.push_back(-1);
            }
            nums.push_back(cur_num);
            cur_num = 0;
        }
        else{
            cur_num = cur_num * 10 + (text[i] - '0');
        }
    }
}
int calculation(){
    int answer = 0;

    for(int i = 0; i< nums.size(); i++){

    }
}
int solution(string &text) {

    int answer = 0;
    preprocess(text);


    return answer;
}

int main() {
    string text;
    cin >> text;

    cout << solution(text);
    return 0;
}