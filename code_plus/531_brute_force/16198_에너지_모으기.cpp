#include <bits/stdc++.h>

using namespace std;

int n;

int go(vector<int> &w){
    int n = w.size();

    if (n == 2) return 0;

    int result = 0;
    for (int i = 1; i < n - 1; i++){
        int e = w[i - 1]*w[i + 1];

        vector<int> arr(w);
        arr.erase(arr.begin() + i);
        e += go(arr);
        result = max(e, result);
    }

    return result;
}

int main(){
    cin>>n;

    vector<int> w(n);

    for (int i = 0; i < n; i++){
        cin>>w[i];
    }

    int result = go(w);

    cout<<result<<'\n';

    return 0;
}
