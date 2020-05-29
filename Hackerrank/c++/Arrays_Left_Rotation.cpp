//
// Created by 박혜원 on 2020/05/02.
//
#include <vector>
#include <iostream>

using namespace std;

void left(vector<int> &a) {

    int temp = a[0];
    int i;
    for (i = 0; i < a.size()- 1; i++) {
        a[i] = a[i + 1];
    }
    a[i] = temp;
}

vector<int> rotLeft(vector<int> a, int d) {

    while (d-- > 0) {
        left(a);
    }
    return a;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int d = 4;
    arr = rotLeft(arr, d);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}