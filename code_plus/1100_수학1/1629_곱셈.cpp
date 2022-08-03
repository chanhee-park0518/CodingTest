#include <bits/stdc++.h>

using namespace std;

long long calc(long long a, long long b, long long c) {
    if (b == 0) {
        return 1;
    }
    else if (b == 1) {
        return a%c;
    }
    else if (b % 2 == 0) {
        long long val = calc(a, b/2, c);
        return (val*val)%c;
    }
    else {
        return (a*calc(a, b - 1, c))%c;
    }
}

int main()
{
    int a,b,c;

    cin>>a>>b>>c;

    long long result = calc(a, b, c);

    cout<<result<<'\n';

    return 0;
}
