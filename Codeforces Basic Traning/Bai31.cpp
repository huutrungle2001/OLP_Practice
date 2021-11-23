#include<bits/stdc++.h>
using namespace std;

int main(){
    int c, k;
    cin >> c >> k;
    int c = 1234567;
    string s = to_string(c);
    cout << (int)s[s.length() - 5] - '0';
}