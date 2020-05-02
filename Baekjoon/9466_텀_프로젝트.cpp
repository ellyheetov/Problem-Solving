//
// Created by 박혜원 on 2020/05/02.
//
#include <iostream>
#include <vector>

#define VISIT 1
#define UNVISIT 0
#define CYCLE 1
#define UNCYCLE 0
using namespace std;

vector<int> inform;
vector<bool> check_cycle;

void initial() {
    int num_size = 0;
    cin >> num_size;

    inform.clear();
    inform.resize(num_size);
    check_cycle.clear();
    check_cycle.resize(num_size);
}

void input() {
    for (int index = 0; index < inform.size(); index++) {
        int x;
        cin >> x;
        inform[index] = x - 1;
    }
}

bool is_cycle(int start_index) {
    int index = inform[start_index];
    if (index >= inform.size())
        return false;

    vector<bool> visit(inform.size(), UNVISIT);

    visit[start_index] = VISIT;
    while (start_index != index) {
        if (visit[index] == VISIT)
            return false;
        visit[index] = VISIT;
        index = inform[index];
    }
    for(int i =0;i<visit.size();i++){
        check_cycle[i] = check_cycle[i] || visit[i];
    }
    return true;
}

void solution() {
    int count = 0;
    for (int index = 0; index < inform.size(); index++){
        if(check_cycle[index] == CYCLE)
            continue;
        if(!is_cycle(index))
            count++;
    }
    cout << count << '\n';
}

int main() {
    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++) {
        initial();
        input();
        solution();
    }
    return 0;
}

/*
2
7
3 1 3 7 3 4 6
8
1 2 3 4 5 6 7 8
 */