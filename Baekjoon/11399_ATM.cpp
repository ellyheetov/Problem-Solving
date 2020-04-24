//
// Created by 박혜원 on 2020/04/06.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> times;

int main()
{
    int n =0;
    int answer=0;
    int sum =0;

    cin >> n;

    for(int i =0; i< n; i++){
        int x;
        cin >> x;
        times.push(x);
    }
    for(int i =0; i< n; i++){
        answer  =  answer + times.top();
        sum = sum + answer;
        times.pop();
    }
    cout << sum;
    return 0;
}