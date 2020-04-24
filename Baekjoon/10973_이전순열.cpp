#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    vector<int> permutation;
    vector<int> nums;

    cin >> n;

    permutation.resize(n);
    for(int i =0;i< n; i++){
        cin >> permutation[i];
    }

    if(prev_permutation(permutation.begin(),permutation.end()))
    {
        for(int i =0; i< n; i++){
            cout << permutation[i] << ' ';
        }
    } else
        cout << "-1";

    return 0;
}