#include <bits/stdc++.h>

using namespace std;

char alpha[256];
int calc(vector<string> &a, vector<char> &letters, vector<int> &d) {
    for (int i = 0; i < (int)letters.size(); i++) {
        alpha[letters[i]] = d[i];
    }

    int sum = 0;
    for (string s : a){
        int cur = 0;
        for (char x : s){
            cur = cur*10 + alpha[x];
        }
        sum += cur;
    }

    return sum;
}

int main() {
    int n;

    cin>>n;
    vector<string> a(n);
    vector<char> letters;

    for (int i = 0; i < n; i++){
        cin>>a[i];
        for (char x : a[i]){
            letters.push_back(x);
        }
    }

    sort(letters.begin(), letters.end());
    letters.erase(unique(letters.begin(), letters.end()), letters.end());

    int m = letters.size();
    vector<int> d;
    for (int i = 9; i > (9 - m); i--){
        d.push_back(i);
    }

    sort(d.begin(), d.end());

    int result = 0;
    do {
        int cur = calc(a, letters, d);
        if (cur > result) result = cur;

    }while(next_permutation(d.begin(), d.end()));

    cout<<result<<'\n';

    return 0;
}
