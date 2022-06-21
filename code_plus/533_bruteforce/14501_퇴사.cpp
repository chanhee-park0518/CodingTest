#include <bits/stdc++.h>

using namespace std;

#define INF 10000000

int n;

vector<pair<int, int>> v;

vector<int> d(20);

int func(int day){
    if (day == n + 1) return 0;

    if (day > n + 1) return -INF;

    if (d[day] != -1) return d[day];

    int t = v[day].first;
    int p = v[day].second;

    int t1 = func(day + t) + p;
    int t2 = func(day + 1);

    d[day] = max(t1, t2);

    return d[day];
}

int main(){
    cin>>n;

    int t, p;

    v.push_back({0, 0});
    for (int i = 1; i <= n; i++){
        cin>>t>>p;
        v.push_back({t, p}); // first, second
        d[i] = -1;
    }

    int result = func(1);

    cout<<result<<'\n';

    return 0;
}
