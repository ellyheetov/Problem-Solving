//
// Created by 박혜원 on 2020/04/01.
//

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

bool find_skill_tree(string &skill, string &skill_tree) {
    map<char, int> pattern;
    int index = 0;
    for (int i = 0; i < skill.length(); i++) {
        pattern.insert(make_pair(skill[i], i ));
    }

    for (int i = 0; i < skill_tree.length(); i++) {
        if (pattern.count(skill_tree[i]) == 0) continue;

        if (index != pattern.find(skill_tree[i])->second)
            return false;
        index++;
    }
    return true;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (int i = 0; i < skill_trees.size(); i++) {
        if (find_skill_tree(skill, skill_trees[i]))
            answer++;
    }
    return answer;
}

int main() {
    string skill = "CBD";
    vector<string> skill_tree;

    skill_tree.push_back("BDA");
    skill_tree.push_back("BACDE");
    skill_tree.push_back("CBADF");
    skill_tree.push_back("AECB");

    cout << solution(skill, skill_tree);

    return 0;
}