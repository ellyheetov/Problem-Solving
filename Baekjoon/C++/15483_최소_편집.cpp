//
// Created by 박혜원 on 2020/03/21.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string target;
string pattern;

vector<vector<int>> compare;

void initialize() {
    compare.resize(pattern.length() + 1);
    for (int i = 0; i <= pattern.length(); i++) {
        compare[i].resize(target.length() + 1);
    }
    compare[0][0] = 0;
    for (int col = 1; col <= target.length(); col++) {
        compare[0][col] = col;
    }
    for (int row = 1; row <= pattern.length(); row++) {
        compare[row][0] = row;
    }
}

void three_min(int row, int col) {
    if(pattern[row] == target[col])
        compare[row+1][col+1] = compare[row][col];
    else{
        compare[row+1][col+1] = min({compare[row][col],compare[row+1][col],compare[row][col+1]}) +1;
    }
}

int find_min_distance() {
    for (int row = 0; row < pattern.length(); ++row) {
        for (int col = 0; col < target.length(); ++col) {
            three_min(row,col);
        }
    }
    return compare[pattern.length()][target.length()];
}

void print() {
    cout << '\n';

    for (int row = 0; row <= pattern.length(); ++row) {
        for (int col = 0; col <= target.length(); ++col) {
            cout << compare[row][col] << " ";
        }
        cout << '\n';
    }
}


int main() {

    cin >> target;
    cin >> pattern;

    initialize();

    cout << find_min_distance();
    print();
    return 0;
}
