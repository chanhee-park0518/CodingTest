#include <bits/stdc++.h>

using namespace std;

int n, m;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

char arr[25][25];

int move(int cnt, int y1, int x1, int y2, int x2){
    if (cnt > 10) return -1;

    bool out1 = false, out2 = false;
    int result = -1;

    if (y1 < 0 || y1 >= n || x1 < 0 || x1 >= m) out1 = true;
    if (y2 < 0 || y2 >= n || x2 < 0 || x2 >= m) out2 = true;

    if (out1 && out2) return -1;
    if (out1 || out2) return cnt;

    for (int i = 0; i < 4; i++) {
        int ny1 = y1 + dy[i];
        int nx1 = x1 + dx[i];
        int ny2 = y2 + dy[i];
        int nx2 = x2 + dx[i];

        if (ny1 >= 0 && ny1 < n && nx1 >= 0 && nx1 < m && arr[ny1][nx1] == '#'){
            ny1 = y1;
            nx1 = x1;
        }

        if (ny2 >= 0 && ny2 < n && nx2 >= 0 && nx2 < m && arr[ny2][nx2] == '#'){
            ny2 = y2;
            nx2 = x2;
        }

        int cur = move(cnt + 1, ny1, nx1, ny2, nx2);
        if (cur == -1) continue;
        if (result == -1 || result > cur){
            result = cur;
        }
    }

    return result;
}

int main(){
    cin>>n>>m;

    int x1,y1,x2,y2;

    x1=y1=x2=y2=-1;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin>>arr[i][j];

            if (arr[i][j] == 'o'){
                if (y1 == -1){
                    y1 = i;
                    x1 = j;
                } else {
                    y2 = i;
                    x2 = j;
                }
                arr[i][j]  = '.';
            }
        }
    }

    int result = move(0, y1, x1, y2, x2);
    cout<<result<<'\n';

    return 0;
}
