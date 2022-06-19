#include <bits/stdc++.h>

using namespace std;

int arr[10][10];

bool c1[10][10];
bool c2[10][10];
bool c3[10][10];
bool domino[10][10];

int dx[] = {0, 1};
int dy[] = {1, 0};

int square(int y, int x){
    return (y/3)*3 + x/3;
}

bool can(int y, int x, int num){
    return c1[y][num] == false && c2[x][num] == false && c3[square(y, x)][num] == false;
}

void check(int y, int x, int num, bool flag){
    c1[y][num] = flag;
    c2[x][num] = flag;
    c3[square(y,x)][num] = flag;
}
bool func(int z){
    if (z == 81) {
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                cout<<arr[i][j]<<' ';
            }
            cout<<'\n';
        }

        return true;
    }

    int y = z/9;
    int x = z%9;

    if (arr[y][x] != 0){
        return func(z+1);
    }
    else {
        for (int k = 0; k < 2; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if (y < 0 || y >= 9 || x < 0 || x >= 9)
                continue;

            if (arr[ny][nx] != 0) continue;

            for (int i = 1; i <= 9; i++){
                for (int j = 1; j <= 9; j++){
                    if (i == j) continue;
                    if (domino[i][j]) continue;
                    if (can(y, x, i) && can(ny, nx, j)) {
                        check(y, x, i, true);
                        check(ny, nx, j, true);
                        domino[i][j] = domino[j][i] = true;
                        arr[y][x] = i;
                        arr[ny][nx] = j;

                        if (func(z + 1)) return true;

                        check(y, x, i, false);
                        check(ny, nx, j, false);
                        domino[i][j] = domino[j][i] = false;
                        arr[y][x] = 0;
                        arr[ny][nx] = 0;
                    }
                } // for j
            } // for i
        } // for k
    }

    return false;
}
int main(){
    int tc = 1;

    while(1){
        memset(arr, 0, sizeof(arr));
        memset(c1, false, sizeof(c1));
        memset(c2, false, sizeof(c2));
        memset(c3, false, sizeof(c3));

        int n;
        cin>>n;

        if (n == 0) break;

        for (int i = 0; i < n; i++){
            int n1, n2;
            string s1, s2;
            cin>>n1>>s1>>n2>>s2;

            int x1, y1, x2, y2;

            y1 = s1[0] - 'A';
            x1 = s1[1] - '1';

            y2 = s2[0] - 'A';
            x2 = s2[1] - '1';

            arr[y1][x1] = n1;
            arr[y2][x2] = n2;
            domino[n1][n2] = domino[n2][n1] = true;
            check(y1, x1, n1, true);
            check(y2, x2, n2, true);
        }

        for (int i = 1; i <= 9; i++){
            string s;
            cin>>s;

            int x, y;
            y = s[0] - 'A';
            x = s[1] - '1';
            arr[y][x] = i;
            check(y, x, i, true);
        }

        cout<<"Puzzle "<<tc<<'\n';
        func(0);
        tc += 1;
    }

    return 0;
}
