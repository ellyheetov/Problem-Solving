//
// Created by 박혜원 on 2020/07/06.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> parents;

void preprocess(int n) {
    parents.resize(n + 1);
    for (int i = 0; i < parents.size(); i++) {
        parents[i] = i;
    }
}

int find_parents(int x) {
    if (x == parents[x]) return x;
    return find_parents(parents[x]);
}

void _union(int x, int y) {
    x = find_parents(x);
    y = find_parents(y);

    parents[y] = x;
    /*
    if(x < y)
        parents[y] = x;
    else
        parents[x] = y;
    */
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    preprocess(n);
    for (int i = 0; i < computers.size(); i++) {
        for (int j = i + 1; j < computers[i].size(); j++) {
            if (computers[i][j] == 0) continue;
            _union(i + 1, j + 1);
        }
    }

    for (int i = 1; i < parents.size(); i++) {
        if (i == parents[i]) answer++;
    }
    return answer;
}

int main() {
    int n = 4;
    vector<vector<int>> computers = {{1,0,0,1},{0,1,1,1},{0,1,1,0},{1,1,0,1}};

    cout << solution(n, computers);
    return 0;
}