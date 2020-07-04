//
// Created by 박혜원 on 2020/07/03.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;

    vector<int> check(n + 1, 1);

    check[0] = 0;
    for (int i = 0; i < lost.size(); i++) {
        check[lost[i]]--;
    }
    for(int i=0;i< reserve.size();i++){
        check[reserve[i]]++;
    }

    for(int i =0;i< lost.size();i++){
        if(check[lost[i]] > 0)
            continue;

        if(check[lost[i] -1] > 1){
            check[lost[i] -1]--;
            check[lost[i]]++;
        }
        else if(lost[i] + 1 < check.size() &&check[lost[i] +1] > 1){
            check[lost[i] +1]--;
            check[lost[i]]++;
        }
    }
    for (int i = 1; i < check.size(); i++) {
        if (check[i] <=0)
            answer--;
    }
    return answer;
}

int main() {
    int n = 5;
    vector<int> lost = {2,4};
    vector<int> reserve = {1,3,5};
    cout << solution(n, lost, reserve);
    return 0;
}