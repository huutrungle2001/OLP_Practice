#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = 0;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[i] < a[j]){
                b[i] ++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << b[i] << " ";
    }
}

0 1 0 1 2
1 0 5 4 2