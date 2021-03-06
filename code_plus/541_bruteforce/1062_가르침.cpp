#include <bits/stdc++.h>

using namespace std;

int count(int mask, vector<int> &words){
    int cnt = 0;

    for (int w : words) {
        if ((w & ((1<<26) -1-mask)) == 0){
            cnt += 1;
        }
    }

    return cnt;
}

int func(int index, int k, int mask, vector<int> &words){
    if (k < 0) return 0;
    if (index == 26){
        return count(mask, words);
    }
    int ans = 0;
    int t1 = func(index+1, k -1, mask | (1<<index), words);
    if (ans < t1) ans = t1;
    if (index != 'a'-'a' && index != 'n'-'a' && index != 't'-'a' && index != 'i'-'a' && index != 'c'-'a'){
        t1 = func(index + 1, k, mask, words);
        if (ans < t1) ans = t1;
    }

    return ans;
}

int main(){
    int n, k;
    cin>>n>>k;

    vector<int> words(n);
    for (int i = 0; i < n; i++){
        string s;
        cin>>s;
        for (char ch : s){
            words[i] |= (1 << (ch - 'a'));
        }
    }

    cout<<func(0, k, 0, words)<<'\n';

    return 0;
}
