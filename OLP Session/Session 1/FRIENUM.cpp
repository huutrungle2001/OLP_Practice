#include<bits/stdc++.h>
using namespace std;

int A[1000001], B[1000001];

void Map(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    unordered_map<int,int> m;
    int temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        m[temp] ++;
    }

    int count = 0;
    for(auto i : m){
        if(i.second > 1){
            count += i.second;
        }
    }

    cout << count;
}

void Array(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
        B[A[i]] ++;
    }

    int count = 0;

    for(int i : B){
        if(i > 1){
            count += i;
        }
    }

    cout << count;
}

int main(){
    // Array();
    Map();
}