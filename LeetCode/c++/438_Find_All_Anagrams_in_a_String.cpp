//
// Created by 박혜원 on 2020/05/05.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
#include <utility>

using namespace std;

class Solution {
public:

    bool compare(vector<int> &countS, vector<int> &countP) {
        for (int i = 0; i < 26; i++) {
            if (countP[i] != countS[i]) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> answer;
        if(s.length() < p.length()) return answer;
        vector<int> countS(26, 0);
        vector<int> countP(26, 0);

        for (int i = 0; i < p.length(); i++) {
            countP[p[i] - 'a']++;
            countS[s[i] - 'a']++;
        }

        for (int i = p.length(); i < s.length(); i++) {
            if (compare(countS, countP))
                answer.push_back(i - p.length());
            countS[s[i] - 'a']++;
            countS[s[i - p.length()] - 'a']--;
        }
        if (compare(countS, countP))
            answer.push_back(s.length() - p.length());
        return answer;
    }
};

int main() {
    string s = "abab";
    string p = "ab";
    vector<int> answer = Solution().findAnagrams(s, p);

    cout << "[";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
    cout << "]";
    return 0;
}

