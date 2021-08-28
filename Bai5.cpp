#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[2*n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i + n] = a[i];
    }
    int answer = INT_MAX;
    for(int i = 0; i < 2*n; i++){
        int sum = 0;
        for(int j = i; j < n+i && n+i <= 2*n; j++){
            sum += a[j];         
            answer = min(answer, sum);
        }
    }
    cout << answer;
}