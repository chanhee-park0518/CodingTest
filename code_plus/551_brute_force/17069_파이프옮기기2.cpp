#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100][100];
long long d[100][100][3];

long long func(int x, int y, int dir) {
    if (x == n-1 && y == n-1) {
        return 1;
    }

    long long &ans = d[x][y][dir];

    if (ans != -1) return ans;
    ans = 0;

    if (dir == 0) {
        if (y+1 < n && arr[x][y+1] == 0) {
            ans += func(x, y+1, 0);
        }
        if (x+1 < n && y+1 < n && arr[x][y+1] == 0 && arr[x+1][y] == 0 && arr[x+1][y+1] == 0) {
            ans += func(x+1, y+1, 1);
        }
    } else if (dir == 1) {
        if (y+1 < n && arr[x][y+1] == 0) {
            ans += func(x, y+1, 0);
        }
        if (x+1 < n && arr[x+1][y] == 0) {
            ans += func(x+1, y, 2);
        }
        if (x+1 < n && y+1 < n && arr[x][y+1] == 0 && arr[x+1][y] == 0 && arr[x+1][y+1] == 0) {
            ans += func(x+1, y+1, 1);
        }
    } else if (dir == 2) {
        if (x+1 < n && arr[x+1][y] == 0) {
            ans += func(x+1, y, 2);
        }
        if (x+1 < n && y+1 < n && arr[x][y+1] == 0 && arr[x+1][y] == 0 && arr[x+1][y+1] == 0) {
            ans += func(x+1, y+1, 1);
        }
    }
    return ans;
}

int main() {
    cin>>n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    memset(d,-1,sizeof(d));

    int result = func(0, 1, 0);

    cout<<result<<'\n';

    return 0;
}
