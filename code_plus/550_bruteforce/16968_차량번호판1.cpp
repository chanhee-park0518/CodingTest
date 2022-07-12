#include <bits/stdc++.h>

using namespace std;

int func(string &s, int index, char last)
{
    if (s.length() == index){
        return 1;
    }

    char start = (s[index] == 'c' ? 'a' : '0');
    char end = (s[index] == 'c' ? 'z' : '9');
    int ans = 0;
    for (char i = start; i <= end; i++) {
        if (i != last) {
            ans += func(s, index+1, i);
        }
    }
    return ans;
}


int main(){
    string s;
    cin>>s;

    int result = func(s, 0, ' ');

    cout<<result<<'\n';

    return 0;
}
