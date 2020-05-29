//
// Created by 박혜원 on 2020/04/23.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    char count[26];

    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        for(int i = 0; i< s.length();i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        for(int i =0; i< 26;i++){
            if(count[i] !=0) return false;
        }
        return true;
    }
};

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    bool result = Solution().isAnagram(str1, str2);
    result ? cout << "true\n" : cout << "false\n";
    return 0;

}
/*
anagram
nagaram
rat
cat
 */