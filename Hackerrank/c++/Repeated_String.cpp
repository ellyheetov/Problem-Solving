//
// Created by 박혜원 on 2020/05/01.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

long repeatedString(string s, long n) {

    int len = s.length();
    vector<int> running_count;

    running_count.resize(len, 0);

    if (s[0] == 'a')
        running_count[0] = 1;

    for (int i = 1; i < len; i++) {
        running_count[i] = running_count[i - 1];
        if (s[i] == 'a')
            running_count[i]++;
    }
    long remaing_count = (n % len == 0) ? 0 : running_count[n % len - 1];
    long total_count = running_count[len-1] * (n/len) + remaing_count;
    return total_count;
}

int main() {
    string str;
    long pattern_size;

    cin >> str;
    cin >> pattern_size;
    cout << repeatedString(str, pattern_size);

    return 0;
}