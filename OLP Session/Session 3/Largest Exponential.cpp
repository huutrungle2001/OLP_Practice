#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> factor;
    for (int i = 2; i <= sqrt(n); i++) {
        while(n % i == 0){
            factor.push_back(i);
        }
    }
    cout << "check";
    for(int i : factor){
        cout << i << " ";
    }
}