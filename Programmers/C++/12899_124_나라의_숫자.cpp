//
// Created by 박혜원 on 2020/07/02.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";

    while (n > 0) {
        int temp = n % 3;
        n = n / 3;

        if(temp == 0) n--;
        switch (temp) {
            case 0:
                answer += "4";
                break;
            case 1:
                answer += "1";
                break;
            case 2:
                answer += "2";
                break;
            default:
                break;
        }
    }
    reverse(answer.begin(),answer.end());
    return answer;
}

int main() {
    int n = 6;
    cout << solution(n);
    return 0;
}