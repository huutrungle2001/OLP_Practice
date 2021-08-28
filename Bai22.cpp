#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[100];
    a[0] = 0;
    int length = 1;
    int n;
    while(cin >> n){
        for(int k = 0; k < n; k++){
            for(int i = 0; i < length; i++){
                a[i+length] = (a[i] + 1)%3;
            }
            length *= 2;
        }
        cout << a[n-1] << endl;
    }
    
    for(int i = 0; i < n; i++){
        cout << a[i];
    }
    int m;
    while(cin >> m){
        cout << a[m-1] << endl;
    }
    int a = 5;
    long long b = 980915130330586982;
    cout << (b > a);
}