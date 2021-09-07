#include<bits/stdc++.h>
using namespace std;

bool check(int a[], int n, int S){
    int temp = 0;
    for(int i = 0; i < n; i++){
        temp += a[i];
        if(temp == S){
            temp = 0;
        }
    }
    return temp == 0 ? true : false;
}

int main(){
    int n, S = 0;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        S += a[i];
    }
    for(int i = n; i >= 1; i--){
        if(S % i == 0 && check(a, n, S/i)){
           cout << i;
           return 0;
        }
    }
}