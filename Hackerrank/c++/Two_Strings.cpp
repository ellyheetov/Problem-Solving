//
// Created by 박혜원 on 2020/05/05.
//

#include <vector>
#include <iostream>
#include <string>
#include <set>

using namespace std;

string twoStrings(string s1, string s2) {
    multiset<char> text;
    for(int i =0;i< s1.length();i++){
        text.insert(s1[i]);
    }
    for(int i =0; i< s2.length();i++){
        if(text.count(s2[i]))
            return "YES";
    }
    return "NO";
}

int main(){
    string s1 = "hi";
    string s2 = "world";

    cout << twoStrings(s1,s2);
}