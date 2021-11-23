#include <bits/stdc++.h>
using namespace std;

int sqr(int x) {
    return x*x;
}

int pow(int a, int b, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0)
        return sqr((int)pow(a, n/2) % b) % b;
    else
        return a * (sqr((int)pow(a, n/2) %b) % b) % b;
}

int main(){
    int a, b, n;
    cin >> a >> b >> n;
    a %= b;
    cout << pow(a, b, n);
}