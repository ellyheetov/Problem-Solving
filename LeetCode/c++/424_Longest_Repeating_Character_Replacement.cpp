//
// Created by 박혜원 on 2020/04/02.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0, end = 0;
        int max_count =0;
        int answer =0;
        unordered_map<char,int> alphabet(26);

        while(end < s.length()){
            max_count = max(max_count, ++alphabet[s[end++]]);
            while(end - start - max_count > k){
                alphabet[s[start++]]--;
            }
            answer = max(answer, end-start);
        }
        return answer;
    }
};


int main() {
    string line = "ABAB";
    //string line = "AABABBA";
    int k = 1;
    cout << Solution().characterReplacement(line, k);
    return 0;
}