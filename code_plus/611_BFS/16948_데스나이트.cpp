#include <bits/stdc++.h>

using namespace std;

int n;
int r1,c1,r2,c2;

int dist[201][201];

int dy[] = {-2, -2,  0,  0,  2,  2};
int dx[] = {-1,  1, -2,  2, -1,  1};

int main(){
    cin>>n;
    cin>>r1>>c1>>r2>>c2;

    for (int i = 0; i < 201; i++){
        for (int j = 0; j < 201; j++){
            dist[i][j] = -1;
        }
    }

    queue<pair<int,int>> q;

    q.push({r1, c1});
    dist[r1][c1] = 0;

    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();

        int cy = cur.first;
        int cx = cur.second;

        for (int i = 0; i < 6; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

            if (dist[ny][nx] == -1){
                dist[ny][nx] = dist[cy][cx] + 1;
                q.push({ny, nx});
            }
        }
    }

    cout<<dist[r2][c2]<<'\n';

    return 0;
}
