//
// Created by 박혜원 on 2020/04/07.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int> &A, int K) {
        int start = 0, end = 0, maxOne = 0;
        int counter = K;
        while (end < A.size()) {
            if(A[end]==0) counter--;
            if(counter < 0){
                if(A[start++]==0) counter++;
            }
            end++;
            maxOne = max(maxOne, end - start);
        }
        return maxOne;
    }
};

int main() {


    //vector<int> vec = {0, 1, 0, 1, 0, 1, 1, 0, 0, 1};
    vector<int> vec = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    //vector<int> vec = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k = 1;

    cout << Solution().longestOnes(vec, k);
    return 0;
}