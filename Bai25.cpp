#include<bits/stdc++.h>
using namespace std;

long long lcm(long long a, long long b){
    return a*b/__gcd(a,b);
}

int main(){
    long long n, p, q, r;
    while(cin >> n >> p >> q >> r){
        long long count = n/lcm(p,q) + n/lcm(r,q) + n/lcm(p,r) - 3*(n/lcm(lcm(p,q),r));
        cout << count << endl;
    }
}