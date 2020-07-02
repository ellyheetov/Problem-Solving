//
// Created by 박혜원 on 2020/07/02.
//

#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    answer.resize(heights.size(), 0);

    for (int index = heights.size() - 1; index >= 0; index--) {
        for (int j = index - 1; j >= 0; j--) {
            if (heights[j] > heights[index]) {
                answer[index] = j + 1;
                break;
            }
        }
    }
    return answer;
}

int main() {
    vector<int> heights = {6, 9, 5, 7, 4};
    vector<int> answer = solution(heights);

    for (int index = 0; index < heights.size(); index++) {
        cout << answer[index] << ' ';

    }
    return 0;
}