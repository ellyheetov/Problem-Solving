#include <iostream>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

struct Compare {
    bool operator()(string a, string b){
        if (a.length() == b.length())
            return a < b;
        else
            return a.length() < b.length();
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test;
    set<string, Compare> words;

    cin >> test;

    for (int i = 0; i < test; i++) {
        string word;
        cin >> word;
        words.insert(word);
    }
    for (auto it = words.begin(); it != words.end(); it++) {
        cout << *it << '\n';
    }
    return 0;
}

