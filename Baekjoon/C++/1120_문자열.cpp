//
// Created by 박혜원 on 2020/03/24.
//

#include <iostream>
#include <string>
#include <set>

using namespace std;

set<int> _count;


int find_minimum_edit_distance(string pattern, string target) {

    int check_count = target.length() - pattern.length() + 1;

    for (int index = 0; index < check_count; index++) {
        int cur_count = 0;

        for (int i = 0; i < pattern.length(); i++) {
            if (target[i + index] != pattern[i])
                cur_count++;
        }
        _count.insert(cur_count);
    }
    return *_count.begin();
}

int main() {

    string pattern, target;
    int answer;

    cin >> pattern >> target;

    answer = find_minimum_edit_distance(pattern, target);

    cout << answer;

    return 0;
}