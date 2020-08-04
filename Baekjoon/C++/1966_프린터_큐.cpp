//
// Created by 박혜원 on 2020/04/02.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(vector<int> &priorities, int location) {
    int answer = 0;

    priority_queue<int> que;
    queue<pair<int,int>> printer;

    for (int i = 0; i < priorities.size(); i++) {
        printer.push({priorities[i], i});
        que.push(priorities[i]);
    }
    while(!que.empty()){
        if(que.top() == printer.front().first){
            answer++;
            if(printer.front().second == location)
                return answer;
            que.pop();
            printer.pop();
        }
        else{
            int value = printer.front().first;
            int index = printer.front().second;

            printer.pop();
            printer.push({value,index});
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test_case;
    int num, location;
    vector<int> priorities;

    cin >> test_case;
    for (int i = 0; i < test_case; i++) {
        cin >> num >> location;
        for (int j = 0; j < num; j++) {
            int x;
            cin >> x;
            priorities.push_back(x);
        }
        cout << solution(priorities, location) << '\n';
        priorities.clear();
    }
    return 0;
}