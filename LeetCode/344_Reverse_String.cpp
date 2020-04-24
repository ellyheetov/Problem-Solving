//
// Created by 박혜원 on 2020/04/13.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start =0, end = s.size() -1;
        if(end < start) return;

        while(start <= end/2){
            char temp = s[end-start];
            s[end - start] = s[start];
            s[start] = temp;
            start++;
        }
    }
};
int main(){
    vector<char> str {'h','e','l','l','o'};
//    vector<char> str {'m','y'};

    Solution().reverseString(str);

    for( auto it : str)
        cout << it;
    return 0;
}