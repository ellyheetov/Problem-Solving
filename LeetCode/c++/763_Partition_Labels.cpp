//
// Created by 박혜원 on 2020/04/23.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <queue>

using namespace std;

class Solution {
public:

    vector<int> partitionLabels(string S)
    {
        vector<int> answer;
        vector<int> alpabet(26, 0);

        for (int i = 0; i < S.length(); i++) {
            alpabet[(int)S[i]-97] = i;
        }
        int start = 0, end = 0;
        for (int i = 0; i < S.length(); i++) {
            end = max(end, alpabet[(int)S[i]-97]);
            if (i == end) {
                answer.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return answer;
    }
};

int main() {

    string target = "eaaaabaaec";
    vector<int> answer;

    answer = Solution().partitionLabels(target);
    cout << "[";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
    cout << "]";
    return 0;
}