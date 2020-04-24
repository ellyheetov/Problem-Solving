//
// Created by 박혜원 on 2020/03/30.
//

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int,int>> taps; // top_height, index
vector<int> answer;

int max_index= -1;
int _max = 0;

void update(int index){
//    if(max_index > index) return;
    max_index = taps[index].second;
    _max = taps[index].first;
}

bool compare_height(int i, int j){
    return taps[i].first < taps[j].first;
}
void solution(){

    for(int i = 0; i<taps.size(); i++){
        max_index= -1;
        _max = 0;
        for(int j = i -1; j>= 0;j--){
            if(compare_height(i,j)) {
                update(j);
                j = -1;
            }
        }
        answer[i] = 1+ max_index;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    taps.resize(N);
    answer.resize(N);

    for(int index =0; index< N; index++){
        int x;
        cin >> x;
        taps[index].first = x;
        taps[index].second = index;
    }
    solution();

    for(int i =0; i< answer.size(); i++){
        cout << answer[i] << " ";
    }

    return 0;
}