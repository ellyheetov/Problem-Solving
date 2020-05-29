//
// Created by 박혜원 on 2020/04/17.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {

        string answer(num1.length() + num2.length(), '0');

        for (int i = num1.length() - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = num2.length() - 1; j >= 0; j--) {
                int sum = carry + num1[i]* num2[j];

            }
        }
    }
};

int main() {
    string num1 = "2";
    string num2 = "3";

    cout << Solution().multiply(num1, num2);
    return 0;
}