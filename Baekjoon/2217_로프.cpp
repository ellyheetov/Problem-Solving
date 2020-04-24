//
// Created by 박혜원 on 2020/03/25.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int rope_count;
    int answer = 0;
    vector<int> rope;

    cin >> rope_count;

    for(int i = 0; i< rope_count ;i++){
        int x;
        cin >> x;
        rope.push_back(x);
    }
    sort(rope.begin(), rope.end());
    for(int i =0; i < rope_count; i++){
        answer = max(answer, rope[i]* (rope_count - i));
    }
    cout << answer;

    return 0;
}
