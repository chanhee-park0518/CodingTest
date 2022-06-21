#include <bits/stdc++.h>

using namespace std;

int r, c;

int dy[] = {1,-1, 0, 0};
int dx[] = {0, 0, -1, 1};

char arr[20][20];
bool check[20][20];

bool alphabet[27];

int result;

void func(int y, int x,int cnt){

    result = max(cnt, result);

    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && ny < r && nx >= 0 && nx < c) {
            int idx = arr[ny][nx] - 'A';
            if (alphabet[idx] == false) {
                alphabet[idx] = true;
                func(ny, nx, cnt + 1);
                alphabet[idx] = false;
            }
        }
    }
}

int main(){
    cin>>r>>c;

    for (int i = 0; i < r; i++){
        string s;
        cin>>s;

        for (int j = 0; j < c; j++){
            arr[i][j] = s[j];
        }
    }

    int idx = arr[0][0] - 'A';

    alphabet[idx] = true;

    func(0,0,1);

    cout<<result<<'\n';

    return 0;
}
