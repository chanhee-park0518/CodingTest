#include <bits/stdc++.h>

using namespace std;

int check(vector<int> &a, vector<int> &op, vector<int> &perm){
    int result = a[0];

    for (int i = 0; i < perm.size(); i++){
        int val = op[perm[i]];

        switch(val){
        case 0:
            result = result + a[i + 1];
            break;
        case 1:
            result = result - a[i + 1];
            break;
        case 2:
            result = result * a[i + 1];
            break;
        case 3:
            result = result / a[i + 1];
            break;
        }
    }

    return result;
}

int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    vector<int> oper;

    for (int i = 0; i < n; i++){
        cin>>a[i];
    }

    for (int i = 0; i < 4; i++){
        int op;
        cin>>op;

        for (int j = 0; j < op; j++){
            oper.push_back(i);
        }
    }

    int m = oper.size();
    vector<int> d;

    for (int i = 0; i < m; i++){
        d.push_back(i);
    }

    int result_min = 1e9;
    int result_max = -1e9;
    do {
        int now = check(a, oper, d);
        result_min = min(result_min, now);
        result_max = max(result_max, now);

    }while(next_permutation(d.begin(), d.end()));

    cout<<result_max<<'\n';
    cout<<result_min<<'\n';
}
