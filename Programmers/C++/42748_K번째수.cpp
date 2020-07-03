//
// Created by 박혜원 on 2020/07/03.
//

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int find_k_num(int start, int end,int k, vector<int> array){
    vector<int> windows;
    for(int i =start -1;i < end;i++){
        windows.push_back(array[i]);
    }
    sort(windows.begin(),windows.end());
    return windows[k-1];
}
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(int i =0;i< commands.size();i++){
        int start = commands[i][0];
        int end = commands[i][1];
        int k = commands[i][2];

        int num = find_k_num(start,end,k,array);
        answer.push_back(num);
    }
    return answer;
}
int main(){
    vector<int> array= {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = {{2,5,3},{4,4,1},{1,7,3}};

    vector<int> answer = solution(array,commands);
    for(int i =0;i< answer.size();i++){
        cout << answer[i] << ' ';
    }
    return 0;
}