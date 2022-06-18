#include <bits/stdc++.h>

using namespace std;

int n;

int arr[20][20];

int check_col[20];
int check_dig[40];
int check_dig2[40];

bool check(int r, int c){
  if (check_col[c]== 1)
    return false;
  
  if (check_dig[r + c] == 1)
    return false;
  
  if (check_dig2[r - c + n - 1] == 1)
    return false;
  
  return true;
}

int calc(int row){
  if (row == n)
    return 1;
  
  int cnt = 0;
  for (int col = 0; col < n; col++){
    if (check(row, col) == 1){
      check_col[col] = 1;
      check_dig[row + col] = 1;
      check_dig2[row + col + n - 1] = 1;
      
      arr[row][col] = 1;
      cnt += calc(row + 1);
      arr[row][col] = 0;
      
      check_col[col] = 0;
      check_dig[row + col] = 0;
      check_dig2[row + col + n - 1] = 0;
    }
  }
  
  return cnt;
}

int main(){
  cin>>n;
  
  int result = calc(0);
  
  cout<<result<<'\n';
  
  return 0;
}
