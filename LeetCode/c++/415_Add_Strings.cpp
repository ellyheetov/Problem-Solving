//
// Created by 박혜원 on 2020/04/23.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.length() < num2.length())
            swap(num1, num2);

        int index = 0;
        int carry = 0;
        string answer;

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        while(index < num2.length()) {
            int temp = carry + (num1[index] - '0') + (num2[index] - '0');
            carry = temp / 10;
            answer += (temp%10 + '0');
            index++;
        }
        while(index < num1.length()){
            int temp = carry + (num1[index++]- '0');
            carry = temp / 10;
            answer += (temp%10 + '0');
        }
        if(carry !=0)
            answer += carry + '0';
        reverse(answer.begin(),answer.end());
        return answer;
    }
};


int main() {
    string num1, num2;
    cin >> num1 >> num2;

    cout << Solution().addStrings(num1, num2);
    return 0;
}
/*
1299
22
 */