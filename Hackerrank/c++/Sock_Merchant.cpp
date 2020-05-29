//
// Created by 박혜원 on 2020/05/01.
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int sockMerchant(int n, vector<int> ar) {
    set<int> inform;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (inform.count(ar[i]) == 0) {
            inform.insert(ar[i]);
            continue;
        }
        inform.erase(ar[i]);
        count++;
    }
    return count;
}

int main() {
    int num_size;
    vector<int> ar;
    cin >> num_size;

    ar.resize(num_size);
    for (int i = 0; i < num_size; i++) {
        cin >> ar[i];
    }
    cout << sockMerchant(num_size, ar);
    return 0;
}


/*
9
10 20 20 10 10 30 50 10 20
 */