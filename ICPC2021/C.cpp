#include<bits/stdc++.h>

using namespace std;
string s;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    cin >> n;
    int res = 1e9;
    char a = 'z', b = 'z';
    for(int i = 1; i < s.size(); i++){
        char u = (s[i] < s[i-1])?s[i]:s[i-1];;
        char v = (s[i] > s[i-1])?s[i]:s[i-1];
        if( a > u || (a == u && b > v)){
            a = u;
            b = v;
        }
    }
    string ans = "";

    
    for(int i = 1; i <= n; i++){
        if( i & 1){
            ans.push_back(a);
        }else{
            ans.push_back(b);
        }
    }
    cout << ans << "\n";
    return 0;
}