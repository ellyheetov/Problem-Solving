//
// Created by 박혜원 on 2020/07/06.
//

#include <vector>
#include <iostream>

using namespace std;


int max_num = 0;
vector<bool> is_prime;

void eratos(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

vector<int> addNum(vector<int> &nums) {
    vector<int> answer;

    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                int sum = nums[i] + nums[j] + nums[k];
                max_num = max(max_num, sum);
                answer.push_back(sum);
            }
        }
    }
    return answer;
}

int solution(vector<int> nums) {
    int answer = 0;

    int size = nums.size();
    if (size < 3) return answer;

    vector<int> addNums = addNum(nums);
    is_prime.resize(max_num + 1, true);
    eratos(max_num);

    for (int i = 0; i < addNums.size(); i++) {
        if (is_prime[addNums[i]]) answer++;
    }
    return answer;
}

int main() {
    vector<int> nums = {1, 2, 3};
    cout << solution(nums);
    return 0;
}

