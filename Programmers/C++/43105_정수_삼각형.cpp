//
// Created by 박혜원 on 2020/07/06.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {

    int answer = 0;

    vector<vector<int>> sample = triangle;

    for (int i = 0; i < triangle.size() - 1; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {

            triangle[i + 1][j] = max(triangle[i][j] + sample[i + 1][j], triangle[i + 1][j]);
            if(j+1 < triangle[i+1].size()) {
                triangle[i + 1][j + 1] = max(triangle[i][j] + sample[i + 1][j + 1], triangle[i + 1][j + 1]);
                answer = max({triangle[i + 1][j], triangle[i + 1][j + 1], answer});
            }
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> triangle = {{7},
                                    {3, 8},
                                    {8, 1, 0},
                                    {2, 7, 4, 4},
                                    {4, 5, 2, 6}};
    cout << solution(triangle);
    return 0;
}