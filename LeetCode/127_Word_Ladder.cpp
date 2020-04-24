//
// Created by 박혜원 on 2020/04/09.
//
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <utility>
#include <map>

using namespace std;

class Solution {
public:
    queue<pair<string, int>> wordque; //word, count

    bool find_next_word(string &cur_str, string &word) {
        int differ_count = 0;
        for (int i = 0; i < word.length(); i++) {
            if (cur_str[i] != word[i])
                differ_count++;
        }
        return differ_count == 1;
    }

    bool is_last(string scr, string dst) {
        return scr == dst;
    }

    void map_initial(vector<string> &wordList, map<string, bool> &check) {
        for (int i = 0; i < wordList.size(); i++)
            check.insert({wordList[i], false});
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        map<string, bool> check;
        map_initial(wordList, check);
        wordque.push({beginWord, 0});

        while (!wordque.empty()) {

            int size = wordque.size();
            for (int turn = 0; turn < size; turn++) {
                string cur_str = wordque.front().first;
                int cnt = wordque.front().second;
                check[cur_str] = true;
                wordque.pop();

                if (is_last(cur_str, endWord))
                    return ++cnt;

                for (int i = 0; i < wordList.size(); i++) {
                    if (find_next_word(cur_str, wordList[i]) && !check[wordList[i]]) {
                        wordque.push({wordList[i], cnt + 1});
                        check.erase(wordList[i]);
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    string beginWord = "hot";
    string endWord = "dog";
    vector<string> wordList = {"hot", "dog", "dot"};

    cout << Solution().ladderLength(beginWord, endWord, wordList);

    return 0;
}