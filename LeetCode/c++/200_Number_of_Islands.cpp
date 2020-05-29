//
// Created by 박혜원 on 2020/04/08.
//

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:

    bool is_boundry(int x, int y,vector<vector<char>> &grid) {
        return x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size();
    }

    void find_island(int x, int y, vector<vector<char>> &grid) {
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        grid[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (is_boundry(new_x, new_y, grid) && grid[new_x][new_y] == '1')
                find_island(new_x, new_y, grid);
        }
    }

    int numIslands(vector<vector<char>> &grid) {
        int cnt = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    find_island(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main() {
    vector<vector<char>> grid = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'0', '0', '0', '0', '0'}
    };

    cout << Solution().numIslands(grid);
}