#include <bits/stdc++.h>

using namespace std;

int n, m;

int arr[500][500];
bool flag[500][500];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int result = 0;

void calc(int y, int x, int sum, int cnt){
    if (cnt == 4){
        result = max(result, sum);
        return;
    }

    if (y < 0 || y >= n || x < 0 || x >= m)
        return;

    if (flag[y][x]) return;

    flag[y][x] = true;

    for (int i = 0; i < 4; i++){
        calc(y + dy[i], x + dx[i], sum + arr[y][x], cnt + 1);
    }

    flag[y][x] = false;
}
int main(){
    cin>>n>>m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin>>arr[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            calc(i, j, 0, 0);
            if (j + 2 < m){
                int temp = arr[i][j] + arr[i][j+1] + arr[i][j+2];
                if (i-1 >= 0){
                    int temp2 = temp + arr[i-1][j+1];
                    result = max(result, temp2);
                }
                if (i+1 < n){
                    int temp2 = temp + arr[i+1][j+1];
                    result = max(result, temp2);
                }
            }
            if (i+2 < n){
                int temp = arr[i][j] + arr[i+1][j] + arr[i+2][j];
                if (j+2 < m){
                    int temp2 = temp + arr[i+1][j+1];
                    result = max(result, temp2);
                }
                if (j-1 >= 0){
                    int temp2 = temp + arr[i+1][j-1];
                    result = max(result, temp2);
                }
            }
        }
    }

    cout<<result<<'\n';
    return 0;
}
