//
// Created by 박혜원 on 2020/05/01.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int jumpingOnClouds(vector<int> c) {

    int count = 0;
    int index = 0;

    while (index < c.size()) {
        count++;
        if (c[index+2] == 0 && index+2 < c.size()) {
            index = index + 2;
            continue;
        }
        index++;
    }
    return --count;
}


int main() {
    int num_size;
    vector<int> c;
    cin >> num_size;

    c.resize(num_size);
    for (int i = 0; i < num_size; i++) {
        cin >> c[i];
    }
    cout << jumpingOnClouds(c);
    return 0;
}

/*
7
0 0 1 0 0 1 0
*/