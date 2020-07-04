//
// Created by 박혜원 on 2020/07/04.
//

#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<bool> PrimeArray;

void eratos(int n) {
    if (n <= 1) return;

    PrimeArray.resize(n + 1, true);

    for (int i = 2; i * i <= n; i++) {
        if (PrimeArray[i]) {
            for (int j = i * i; j <= n; j += i)
                PrimeArray[j] = false;
        }
    }
}

int solution(int n) {
    int answer = 0;

    eratos(n);
    for (int i = 2; i <= n; i++) {
        if (PrimeArray[i])
            answer++;
    }
    return answer;
}

int main() {
    int n = 10;
    cout << solution(n);
    return 0;
}