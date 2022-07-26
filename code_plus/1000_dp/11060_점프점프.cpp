#inlcude <bits/stdc++.h>

using namespace std;

int n;

int A[101];
int d[101];

int main(){
  cin>>n;
  
  for (int i = 0; i < n; i++)
    cin>>A[i];
  
  fill(d, d + 101, -1);
  
  d[0] = 0;
  for (int i = 1; i < n; i++){
    for (int j = 0; j < i; j++){
      if (d[j] != -1 && i - j <= A[j]){
        if (d[i] == -1 || d[i] > d[j] + 1)
          d[i] = d[j] + 1;
      }
    }
  }
  
  cout<<d[n-1]<<'\n';
  
  return 0;
}
