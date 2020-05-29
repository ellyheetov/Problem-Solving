//
// Created by 박혜원 on 2020/05/12.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:


    char findTheDifference(string s, string t) {

        vector<int> alphabet(26, 0);
        vector<int> my(26, 0);

        for (int i = 0; i < s.length(); i++) {
            alphabet[s[i] - 'a']++;
        }
        for(int i =0;i< t.length();i++){
            my[t[i] - 'a']++;
        }

        for (int i = 0; i < t.length(); i++) {
            if (alphabet[t[i]- 'a'] != my[t[i] - 'a'])
                return t[i];
        }
        return NULL;
    }
};

int main() {
    string s = "bcd";
    string t = "abcde";
    cout << Solution().findTheDifference(s, t);

    return 0;
}