//
// Created by 박혜원 on 2020/05/05.
//

#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

bool have(multiset<string> &s, string &str) {
    return s.count(str);
}

void checkMagazine(vector<string> magazine, vector<string> note) {
    multiset<string> s;

    for (int i = 0; i < magazine.size(); i++) {
        s.insert(magazine[i]);
    }
    for (int i = 0; i < note.size(); i++) {
        if (!have(s, note[i])) {
            cout << "No";
            return;
        }
        auto it = s.find(note[i]);
        if(it!= s.end())
            s.erase(it);
    }
    cout << "Yes";
    return;
}

int main() {
    vector<string> target = {"two", "two", "two","owt"};
    vector<string> pattern = {"two", "two"};

    checkMagazine(target, pattern);
    return 0;
}