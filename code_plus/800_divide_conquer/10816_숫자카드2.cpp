#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;

    cin>>n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    cin>>m;
    for (int i = 0; i < m; i++){
        int num;
        cin>>num;

        auto p = equal_range(arr.begin(), arr.end(), num);
        int result = p.second - p.first;
        cout<<result<<" ";
    }

    cout<<'\n';

    return 0;
}
