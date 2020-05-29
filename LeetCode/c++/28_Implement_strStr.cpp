//
// Created by 박혜원 on 2020/04/14.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        if(haystack.size() < needle.size()) return -1;

        for(auto i = 0; i <= haystack.size()-needle.size(); i++){
            if(needle[0] != haystack[i]) continue;

            for(int j =0; true; j++){
                if(j == needle.size()) return i;
                if(needle[j] != haystack[i+j]) break;
            }
        }
        return -1;
    }
};

int main() {
    string haystack = "hello";
    string needle = "ll";

    cout << Solution().strStr(haystack, needle);

    return 0;
}