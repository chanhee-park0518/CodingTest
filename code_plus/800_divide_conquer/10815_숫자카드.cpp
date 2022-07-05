#include <bits/stdc++.h>

using namespace std;

int n, m;

int arr[500001];

int binarySearch(int num){
    int l = 0;
    int r = n - 1;

    while (l <= r) {
        int mid = (l + r)/2;

        if (arr[mid] == num) return 1;
        else if (arr[mid] > num) r = mid - 1;
        else l = mid + 1;
    }

    return 0;
}

int main(){
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }

    cin>>m;
    for (int i = 0; i < m; i++){
        int num;
        cin>>num;
        int result = binarySearch(num);
        cout<<result<<" ";
    }
    cout<<'\n';

    return 0;
}
