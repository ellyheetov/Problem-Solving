//
// Created by 박혜원 on 2020/05/12.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (!n) return 0;

        bool arr[n];
        for(int i =0;i< n;i++)
            arr[i] = false;

        int ans = 0;

        for (long i = 2; i < n; i++) {
            if (!arr[i]) {
                ans++;
                for (long j = i * i; j < n; j = j+i)
                    arr[j] = true;
            }
        }
        return ans;
    }
};

int main() {

    cout << Solution().countPrimes(10);
    return 0;
}