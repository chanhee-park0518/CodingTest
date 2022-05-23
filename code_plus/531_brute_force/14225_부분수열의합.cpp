#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> s(25);
bool c[20*100000 + 10];

void func(int idx, int sum)
{
    if (idx >= n){
        c[sum] = true;
        return;
    }

    func(idx + 1, sum + s[idx]);
    func(idx + 1, sum);
}

int main(){
    cin>>n;

    for (int i = 0; i < n; i++) {
        cin>>s[i];
    }

    func(0, 0);

    int i = 1;
    while(1) {
        if (c[i] == false)
            break;
        i++;
    }

    cout<<i<<'\n';
}
