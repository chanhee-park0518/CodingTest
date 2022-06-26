#include <bits/stdc++.h>

using namespace std;

int n, m;

int next1[101];
int dist[101];

queue<int> q;

int main(){
    cin>>n>>m;

    for (int i = 1; i <= 100; i++){
        next1[i] = i;
        dist[i] = -1;
    }

    int x,y;
    while(n--){
        cin>>x>>y;
        next1[x] = y;
    }

    while(m--){
        cin>>x>>y;
        next1[x] = y;
    }

    dist[1] = 0;
    q.push(1);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for (int i=1; i <=6; i++){
            int y = x+i;
            if (y> 100) continue;
            y = next1[y];
            if (dist[y] == -1){
                dist[y] = dist[x] + 1;
                q.push(y);
            }
        }
    }

    cout<<dist[100]<<'\n';

    return 0;
}
