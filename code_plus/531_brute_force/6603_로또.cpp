#include <bits/stdc++.h>

using namespace std;

#define MAX_NUMBER 100

int n, k;

vector<int> choice(MAX_NUMBER);
vector<int> arr(MAX_NUMBER);
vector<int> input(MAX_NUMBER);

void comp(int number, int idx){
    if (idx > k){
       for (int i = 1; i <= k; i++){
           int index = choice[i];
           cout<<input[index]<<' ';
       }
       cout<<'\n';
       return;
    }

    if (number > n) {
        return;
    }

    choice[idx] = arr[number];

    comp(number + 1, idx + 1);
    comp(number + 1, idx);
}
int main(){
    while(1) {
        cin>>n;
        if (n == 0)
            break;

        fill(choice.begin(), choice.end(), 0);
        fill(arr.begin(), arr.end(), 0);
        fill(input.begin(), input.end(), 0);

        for (int i = 1; i <= n; i++)
            cin>>input[i];

        k = 6;

        for (int i = 1; i <= n; i++){
            arr[i] = i;
        }

        comp(1, 1);
        cout<<'\n';
    }

    return 0;
}
