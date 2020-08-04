//
// Created by 박혜원 on 2020/04/01.
//

#include <iostream>
#include <vector>

#define MAX 10007

using namespace std;

vector<vector<int>> binomial;

void place_resize(int n){
    binomial.resize(n+1);
    for(int i =0; i<= n; i++){
        binomial[i].resize(n,1);
    }
}
void solution(int n, int r){
    for(int i =1; i<= n;i++){
        for(int j =0; j<= n; j++) {
            if(i == j || j ==0)
                binomial[i][j] = 1;
            else
                binomial[i][j] = (binomial[i-1][j-1] + binomial[i-1][j]) % MAX;
        }
    }
}
int main() {
    int n, r;
    int answer = 1;
    cin >> n >> r;

    place_resize(n);
    solution(n,r);

    cout << binomial[n][r];

    return 0;
}

