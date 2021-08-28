#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, highway, answer = 0;
    cin >> n;
    int y[n];
    for(int i = 0; i < n; i++){
        cin >> y[i] >> y[i];
    }
    sort(y, y + n);
    highway = y[n/2];
    for(int i : y){
        answer += abs(highway - i);
    }
    cout << answer << endl;
}