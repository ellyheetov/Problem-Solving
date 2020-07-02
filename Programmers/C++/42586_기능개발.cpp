//
// Created by 박혜원 on 2020/07/01.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> que;

    for (int index = 0; index < progresses.size(); index++) {
        int remain = 100 - progresses[index];
        int needdays = remain / speeds[index];
        if (remain % speeds[index] != 0)
            needdays++;
        que.push(needdays);
    }
    if (que.empty()) return answer;

    int bound = que.front();
    int cnt = 0;

    while (!que.empty()) {
        if (que.front() <=bound) {
            cnt++;
            que.pop();
        }else {
            answer.push_back(cnt);
            bound = que.front();
            cnt = 0;
        }
    }
    answer.push_back(cnt);
    return answer;
}

int main() {
    vector<int> progresses = {5, 5, 5};
    vector<int> speeds = {21, 25, 20};

    vector<int> answer = solution(progresses, speeds);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
    return 0;
}