//
// Created by 박혜원 on 2020/05/28.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> parents;

    int find_set(int x) {
        if (x == parents[x]) return x;
        return find_set(parents[x]);
    }

    void union_sets(int x, int y) {
        x = find_set(x);
        y = find_set(y);
        if (y == x) return;
        if (x > y) swap(x, y);
        parents[y] = x;
    }

    void preprocess(int size) {
        parents.resize(size + 1);
        for (int i = 1; i <= size; i++) {
            parents[i] = i;
        }
    }

    int circleNum() {
        int cnt = 0;
        for (int i = 1; i < parents.size(); i++) {
            if (parents[i] == i) cnt++;
        }
        return cnt;
    }

    int findCircleNum(vector<vector<int>> &M) {
        preprocess(M.size());

        for (int i = 0; i < M.size(); i++) {
            for (int j = i + 1; j < M.size(); j++) {
                if (M[i][j] == 1)
                    union_sets(i + 1, j + 1);
            }
        }
        return circleNum();
    }
};

int main() {

    vector<vector<int>> M = {{1, 1, 0},
                             {1, 1, 1},
                             {0, 1, 1}};
    cout << Solution().findCircleNum(M);
}