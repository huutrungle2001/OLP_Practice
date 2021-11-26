#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long a, b, n;
    long long result = 1;
    long long gd = 2;
    cin >> a >> b >> n;

    while (n-- && gd > 1) {
        gd = __gcd(a, b);
        result *= gd;
        b /= gd;
    }

    cout << result;
    return 0;
}