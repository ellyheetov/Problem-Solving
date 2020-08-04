//
// Created by 박혜원 on 2020/03/28.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> answer;

long long n;

void initialization() {
    answer.resize(n + 1, 0);
    answer[0] = 0;
    answer[1] = 0;
}

int solution() {
    for (int i = 2; i <= n; i++) {
        answer[i] = 1 + answer[i - 1];
        if (i % 3 == 0) answer[i] = min(answer[i], 1 + answer[i / 3]);
        if (i % 2 == 0) answer[i] = min(answer[i], 1 + answer[i / 2]);
    }
    return answer[n];
}

int main() {

    cin >> n;
    initialization();

    cout << solution();

    return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> answer;

long long n;

void initialization() {
    answer.resize(n + 1, 0);
    answer[0] = 0;
    answer[1] = 0;
}

int solution() {
    for (int i = 2; i <= n; i++) {

        if (i % 2 == 0 && i % 3 == 0)answer[i] = 1 + min({answer[i / 2], answer[i / 3], answer[i - 1]});
        else if (i % 2 == 0) answer[i] = 1 + min(answer[i / 2], answer[i - 1]);
        else if (i % 3 == 0) answer[i] = 1 + min(answer[i / 3], answer[i - 1]);
        else answer[i] = 1 + answer[i - 1];

    }
    return answer[n];
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    initialization();

    cout << solution();

    return 0;
}*/
