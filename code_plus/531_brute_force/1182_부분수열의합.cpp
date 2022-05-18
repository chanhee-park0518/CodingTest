#include <bits/stdc++.h>

using namespace std;

int n, s;

vector<int> v;

int result;

void func(int index, int sum) {
    if (index == n) {
        if (sum == s) {
            result += 1;
        }
        return;
    }

    func(index + 1, sum + v[index]);
    func(index + 1, sum);
}

int main(){
    cin>>n>>s;

    for (int i = 0; i < n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    func(0, 0);

    if (s == 0) result -= 1;

    cout<<result<<'\n';

    return 0;
}
