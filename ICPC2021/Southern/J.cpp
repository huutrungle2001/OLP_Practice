#include<bits/stdc++.h>
#define N 5000
using namespace std;
int m, n;
string s[N];
int res = 0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >>  m >> n;
    int l[m][n], r[m][n], top[m][n], bot[m][n];
    for(int i = 0; i < m ;i++){
        cin >> s[i];
    }

    for (int i = 0; i < n; i++){
        top[0][i] = s[0][i]-'0';
        bot[m - 1][i] = s[m - 1][i]-'0';
    }
    for(int i = 0; i < m; i++){
        l[i][0] = s[i][0]-'0';
        r[i][n - 1] = s[i][n- 1]-'0';
    }
    for (int i = 0; i < m; i++){
        for (int j = 1; j < n; j++){
            if (s[i][j] == '1'){
                l[i][j] = l[i][j - 1] + 1;
            }else{
                l[i][j] = 0;
            }
            j = n - 1 - j;
            if (s[i][j] == '1'){
                r[i][j] = r[i][j + 1] + 1;
            }else{
                r[i][j] = 0;
            }
            j = n-1-j;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 1; j < m; j++){
            if (s[j][i] == '1'){
                top[j][i] = top[j - 1][i] + 1;
            }else{
                top[j][i] = 0;
            }
            j = m - 1 - j;
            if (s[j][i] == '1'){
                bot[j][i] = bot[j + 1][i] + 1;
            }else{
                bot[j][i] = 0;
            }
            j = m-1-j;
        }
    }
	int a, b;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            int len = min(min(top[i][j], bot[i][j]),min(l[i][j], r[i][j]));
            if( res < len){
            	res = len;
            	a = i;
            	b = j;
            }
        }
    }
    (res > 0)? cout << (4*res-3) << "\n" << a+1 << " " << b+1 << "\n" : cout << -1 << "\n";
    return 0;
}