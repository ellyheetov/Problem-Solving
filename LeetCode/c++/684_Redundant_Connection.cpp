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

    void Union(int x, int y) {
        x = Find(x);
        y = Find(y);
        if (y == x) return;
        if (x > y) swap(x, y);
        parents[y] = x;
    }

    int Find(int x) {
        if (x == parents[x])
            return x;
        else return Find(parents[x]);
    }

    void preprocess(int size) {
        parents.resize(size + 1);
        for (int i = 1; i < size; i++) {
            parents[i] = i;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        preprocess(edges.size());

        for (auto it : edges) {
            if (Find(it.front()) == Find(it.back())) return it;
            Union(it.front(), it.back());
        }
        return {0, 0};
    }
};

int main() {
    vector<vector<int>> edges = {{1, 2},
                                 {2, 3},
                                 {3, 4},
                                 {1, 4},
                                 {1, 5}};
    vector<int> answer = Solution().findRedundantConnection(edges);

    cout << answer[0] << ' ' << answer[1];
}
