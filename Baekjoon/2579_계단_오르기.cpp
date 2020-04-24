//
// Created by 박혜원 on 2020/03/23.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> stair;
vector<int> cache;

void initialize() {
    cache[0] = stair[0];
    cache[1] = stair[0] + stair[1];
    cache[2] = stair[2] + max(stair[0], stair[1]);
}

int max_score() {
    initialize();

    for (int i = 3; i < stair.size(); i++) {
        cache[i] = stair[i] + max(stair[i-1] + cache[i - 3],cache[i-2]);
    }
    return cache[cache.size() - 1];
}

int main() {
    int input_size;
    int answer;
    cin >> input_size;

    stair.resize(input_size,0);
    cache.resize(input_size,0);
    for (int i = 0; i < input_size; i++) {
        int x;
        cin >> x;
        stair[i] = x;
    }
    answer = max_score();
    cout << answer;

    return 0;
}