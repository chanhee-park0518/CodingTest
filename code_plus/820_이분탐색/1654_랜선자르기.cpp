#include <bits/stdc++.h>

using namespace std;

int n, m;

long long a[10000];

bool check(long long x) {
    int cnt = 0;
    for (int i=0; i<n; i++) {
        cnt += a[i]/x;
    }
    return cnt >= m;
}

int main() {
    cin>>n>>m;
    long long max = 0;
    for (int i = 0; i < n; i++) {
        cin>>a[i];
        if (max < a[i]) {
            max = a[i];
        }
    }
  
    long long ans = 0;
    long long l = 1;
    long long r = max;
    while (l <= r) {
        long long mid = (l+r)/2;
        if (check(mid)) {
            if (ans < mid) {
                ans = mid;
            }
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
