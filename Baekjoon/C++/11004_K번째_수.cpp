//
// Created by 박혜원 on 2020/03/21.
//

#include <iostream>
#include <queue>

using namespace std;

priority_queue<int,vector<int>,greater<int>> min_heap;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N,K;

    cin >> N >> K;

    for(int i=0; i< N; i++){
        int x;
        cin >> x;
        min_heap.push(x);
    }
    for(int i=1; i< K; i++){
        min_heap.pop();
    }
    cout << min_heap.top();

    return 0;
}