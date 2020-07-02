//
// Created by 박혜원 on 2020/07/02.
//

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>, greater<int>> que;

    for(int i =0; i< scoville.size();i++){
        que.push(scoville[i]);
    }
    while(que.top() < K && que.size() >= 2){
        int first = que.top();
        que.pop();
        int second = que.top();
        que.pop();

        int next = first + second*2;
        que.push(next);
        answer++;
    }
    if(que.top() < K) return -1;
    return answer;
}

int main(){
    cout << solution({1,2},7);
    return 0;
}