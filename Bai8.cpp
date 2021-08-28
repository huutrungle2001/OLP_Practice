#include<bits/stdc++.h>
using namespace std;

bool check(int a[], int n, int m){
    if(n % m != 0) return false;
    for(int i = m; i < n; i ++){
        if(a[i] != a[i%m]){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 1; i < n; i++){
        if(check(a, n, i)){
            cout << i;
            return 0;
        }
    }    
}