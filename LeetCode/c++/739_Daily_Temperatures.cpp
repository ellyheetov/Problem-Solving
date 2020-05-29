//
// Created by 박혜원 on 2020/04/28.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &T) {
        vector<int> result;
        result.resize(T.size(), 0);
        stack<int> st;
        for (int index = T.size() - 1; index >= 0; --index) {
            while (!st.empty() && T[index] >= T[st.top()])
                st.pop();
            result[index] = st.empty() ? 0 : st.top() - index;
            st.push(index);
        }
        return result;
    }
};

int main() {
    vector<int> temper = {73, 74, 75, 71, 69, 72, 76, 74};
    vector<int> answer;
    answer = Solution().dailyTemperatures(temper);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
    return 0;
}