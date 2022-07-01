#include <bits/stdc++.h>

using namespace std;

int n, k;

int coin[11];

int main(){
    cin>>n>>k;

    for (int i = 0; i < n; i++)
        cin>>coin[i];

    int cnt = 0;

    for (int i = n - 1; i >= 0; i--){
        if (k == 0) break;

        int m = k/coin[i];

        if (m > 0){
            k -= m*coin[i];
            cnt += m;
        }
    }

    cout<<cnt<<'\n';

    return 0;
}
