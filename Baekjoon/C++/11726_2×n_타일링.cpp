//
// Created by 박혜원 on 2020/03/27.
//

#include <iostream>

using namespace std;

int tile[1001];

void initial() {
    tile[0] = 1;
    tile[1] = 1;
}

int tiling(int n) {
    for (int i = 2; i <= n; i++) {
        tile[i] = (tile[i - 1] + tile[i - 2]) % 10007;
    }
    return tile[n];
}

int main() {

    int n;
    cin >> n;
    initial();

    cout << tiling(n);

    return 0;
}