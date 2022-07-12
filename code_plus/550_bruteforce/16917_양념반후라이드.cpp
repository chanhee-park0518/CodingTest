#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, x, y;
    cin>>a>>b>>c>>x>>y;

    int result = x*a + y*b;

    for (int i=1; i<=100000; i++) {
        int x_max = max(0, x-i);
        int y_max = max(0, y-i);
        int p = 2*i*c + x_max*a + y_max*b;
        if (result > p) result = p;
    }

    cout<<result<<'\n';

    return 0;
}
