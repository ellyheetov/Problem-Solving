//
// Created by 박혜원 on 2020/05/01.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

int countingValleys(int n, string s) {
    int count = 0;
    int valleys = 0;
    for(int i =0; i< n; i++){
        if(s[i]=='D') {
            count--;
            continue;
        }
        count++;
        if (count == 0)
            valleys++;
    }
    return valleys;
}

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int result = countingValleys(n, s);

    cout << result << "\n";


    return 0;
}
