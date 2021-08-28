#include<bits/stdc++.h>
using namespace std;

int sum(int a[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
    }

    return sum;
}

int main(){
    int n, count = 0;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    do{
        int s = a[n-1] + a[n-2] + a[n-3];
        if(s >= sum(a, n - 3)){
            n -= 1;
            count ++;
            if(n < 4){
                count = -1;
            }
        }else{
            break;
        }
    }while(count != -1);
    cout << count << endl;
}