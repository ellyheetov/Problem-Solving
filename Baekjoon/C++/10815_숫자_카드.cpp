//
// Created by 박혜원 on 2020/03/14.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binary_search(vector<int>& v,int first, int last, int k)
{
    if(last < first)
        return false;
    int mid = (first + last)/2;
    if(k == v[mid])
        return true;
    else if(k > v[mid])
        return binary_search(v,mid+1, last, k);
    else
        return binary_search(v,first,mid-1,k);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    int problem;
    int x;
    vector<int> number_card;
    cin >> T;

    for(int i = 0; i< T; i++)
    {
        cin >> x;
        number_card.push_back(x);
    }
    int last_index = T-1;
    sort(number_card.begin(), number_card.end());

    cin >> problem;
    for(int i = 0; i< problem; i++ )
    {
        cin >> x;
        if( binary_search(number_card,0,last_index,x))
            cout << "1 ";
        else
            cout << "0 ";
    }
    return 0;
}
