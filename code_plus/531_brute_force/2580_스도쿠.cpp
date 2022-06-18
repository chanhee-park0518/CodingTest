#include <bits/stdc++.h>

using namespace std;

int arr[10][10];

bool c1[10][10];
bool c2[10][10];
bool c3[10][10];

int square(int y, int x){
    return (y/3)*3 + x/3;
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

    if (arr[y][x] != 0) {
        return func(z + 1);
    }
    else {
        for (int i = 1; i <= 9; i++){
            if (c1[y][i] == false && c2[x][i] == false && c3[square(y, x)][i] == false){

                c1[y][i] = c2[x][i] = c3[square(y, x)][i] = true;

                arr[y][x] = i;

                if (func(z + 1)) return true;

                arr[y][x] = 0;

                c1[y][i] = c2[x][i] = c3[square(y, x)][i] = false;
            }
        }
    }

    return false;
}

int main(){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cin>>arr[i][j];

            if (arr[i][j] != 0) {
                c1[i][arr[i][j]] = true;
                c2[j][arr[i][j]] = true;
                c3[square(i, j)][arr[i][j]] = true;
            }
        }
    }

    func(0);

    return 0;
}
