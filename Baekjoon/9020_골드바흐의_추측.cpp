//
// Created by 박혜원 on 2020/04/11.
//

#include <iostream>
#include <vector>
#include <cmath>

#define MAX_SIZE 10000
#define PRIME 1
#define NOTPRIME 0
using namespace std;

int prime[MAX_SIZE + 1];

bool is_prime_number(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0)
            return NOTPRIME;
    }
    return PRIME;
}

void set_prime_number(int num) {
    for (int i = 2; i < num; i++) {
        if (is_prime_number(i))
            prime[i] = i;
    }
}

vector<int> solution(int num) {
    set_prime_number(num);

    int mid = num / 2;
    for (int i = mid; i > 0; i--) {
        if (prime[i] + prime[num - i] == num)
            return vector<int>{i,num-i};
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++) {
        int num;
        cin >> num;
        vector<int> answer = solution(num);
        cout << answer[0] << ' ' << answer[1] << '\n';
    }
}