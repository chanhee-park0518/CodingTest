#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> v;

int main(){
    int n;
    cin>>n;

    for (int i = 0; i < n; i++){
        int s, e;
        cin>>s>>e;
        v.push_back({s, e});
    }

    sort(v.begin(), v.end());

    int e = v[0].second;
    int result = 1;

    for (int i = 1; i < n; i++){
        int cs = v[i].first;
        int ce = v[i].second;

        if (cs >= e){
            e = ce;
            result += 1;
        }
        else if (e > ce){
            e = ce;
        }
    }

    cout<<result<<'\n';

    return 0;
}
