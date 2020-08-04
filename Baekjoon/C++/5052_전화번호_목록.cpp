//
// Created by 박혜원 on 2020/04/11.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> number;


void solution(){
    string pattern = number[0];
    int count = 0;
    for(int i = 1; i< number.size(); i++){
        for(int j =0; j< pattern.length();j++){
            if(number[i][j] == pattern[j]) {
                count++;
            }
        }
        if(count == pattern.length()){
            cout << "NO\n";
            return;
        } else count = 0;
    }
    cout << "YES\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++) {
        int size;
        cin >> size;
        number.clear();

        for (int j = 0; j < size; j++) {
            string str;
            cin >> str;
            number.push_back(str);
        }
        solution();
    }
    return 0;
}