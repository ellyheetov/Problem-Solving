//
// Created by 박혜원 on 2020/05/02.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hourglass(int x, int y, vector<vector<int>> &arr) {
    return arr[x][y] + arr[x][y + 1] + arr[x][y + 2]
           + arr[x + 1][y + 1]
           + arr[x + 2][y] + arr[x + 2][y + 1] + arr[x + 2][y + 2];
}

int hourglassSum(vector<vector<int>> arr) {

    int max_sum = INT_MIN;

    for (int index_x = 0; index_x + 2 < arr.size(); index_x++) {
        for (int index_y = 0; index_y + 2 < arr.size(); index_y++)
            max_sum = max(max_sum, hourglass(index_x, index_y, arr));
    }
    return max_sum;
}

int main() {
    vector<vector<int>> arr;
    arr.resize(6);

    for (int i = 0; i < arr.size(); i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
    }
    cout << hourglassSum(arr);

    return 0;
}
/*
1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 2 4 4 0
0 0 0 2 0 0
0 0 1 2 4 0
 */