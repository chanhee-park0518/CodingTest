#include <bits/stdc++.h>

using namespace std;

bool check[10001];
int dist[10001];
char how[10001];
int from[10001];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        memset(check,false,sizeof(check));
        memset(dist,0,sizeof(dist));
        memset(how,0,sizeof(how));
        memset(from,0,sizeof(from));
        check[n] = true;
        dist[n] = 0;
        from[n] = -1;
        queue<int> q;
        q.push(n);
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            int next = (now*2) % 10000;
            if (check[next] == false) {
                q.push(next);
                check[next] = true;
                dist[next] = dist[now]+1;
                from[next] = now;
                how[next] = 'D';
            }
                      next = now-1;
            if (next == -1) next = 9999;
            if (check[next] == false) {
                q.push(next);
                check[next] = true;
                dist[next] = dist[now]+1;
                from[next] = now;
                how[next] = 'S';
            }
            next = (now%1000)*10 + now/1000;
            if (check[next] == false) {
                q.push(next);
                check[next] = true;
                dist[next] = dist[now]+1;
                from[next] = now;
                how[next] = 'L';
            }
            next = (now/10) + (now%10)*1000;
            if (check[next] == false) {
                q.push(next);
                check[next] = true;
                dist[next] = dist[now]+1;
                from[next] = now;
                how[next] = 'R';
            }
        }

        string ans = "";
        while (m != n) {
            ans += how[m];
            m = from[m];
        }
        reverse(ans.begin(), ans.end());
        cout << ans<<'\n';
    }
    return 0;
}
