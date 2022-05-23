#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> A(12);
vector<int> O(4);

int max_val;
int min_val;

void calc(int idx, int num, int plus, int minus, int mul, int div)
{
    if (idx == n){
        if (max_val < num) max_val = num;
        if (min_val > num) min_val = num;
        return;
    }

    if (plus > 0) {
        calc(idx + 1, num + A[idx], plus - 1, minus, mul, div);
    }

    if (minus > 0) {
        calc(idx + 1, num - A[idx], plus, minus - 1, mul, div);
    }

    if (mul > 0) {
        calc(idx + 1, num * A[idx], plus, minus, mul - 1, div);
    }

    if (div > 0) {
        calc(idx + 1, num/A[idx], plus, minus, mul, div - 1);
    }
}

int main(){
    cin>>n;

    for (int i = 0; i < n; i++) {
        cin>>A[i];
    }

    for (int i = 0; i < 4; i++) {
        cin>>O[i];
    }

    min_val = 1e9;
    max_val = -1e9;

    calc(1, A[0], O[0], O[1], O[2], O[3]);

    cout<<max_val<<'\n';
    cout<<min_val<<'\n';

    return 0;
}
