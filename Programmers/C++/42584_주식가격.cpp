//
// Created by 박혜원 on 2020/07/01.
//
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> s;
    int size = prices.size();

    for (int i = 0; i < size; i++) {
        while (!s.empty() && prices[s.top()] > prices[i]) {
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) {
        answer[s.top()] = size - s.top() - 1;
        s.pop();
    }
    return answer;
}

int main() {
    vector<int> prices = {1,2,3,2,3};
    vector<int> answer = solution(prices);
}