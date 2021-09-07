#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    map<int, int> store;
    for(int i = 0; i < n; i++){
        store[a[i]]++;
    }
    cout << store.size() << endl;
    for(auto i : store){
        cout << i.first << " " << i.second << endl;
    }
}