#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> s;

int check[20*10000 + 10];

int main(){
    cin>>n;

    for (int i = 0; i < n; i++){
        int data;
        cin>>data;

        s.push_back(data);
    }

    for (int i = 0; i < (1<<n); i++){
        int sum = 0;
        for (int j = 0; j < n; j++){
            if (i & (1<<j)){
                sum += s[j];
            }
        }
        check[sum] = true;
    }

    int i = 1;
    while(1){
        if (check[i] == false){
            cout<<i<<'\n';
            break;
        }
        i++;
    }

    return 0;
}
