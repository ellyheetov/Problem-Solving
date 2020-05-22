//
// Created by 박혜원 on 2020/04/08.
//
#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;


string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    multiset<string> name;

    for (int i = 0; i < completion.size(); ++i) {
        name.insert(completion[i]);
    }
    for (int i = 0; i < participant.size(); i++) {
        if(name.find(participant[i]) != name.end())
            name.erase(participant[i]);
        else
            answer = participant[i];
    }
    return answer;
}

int main() {
    vector<string> participant = {"kiki", "eden","leo","leo"};
    vector<string> completion = {"eden", "kiki","leo"};

    cout << solution(participant, completion);
}