#include <cmath>
#include <iostream>
using namespace std;
long long path(long long a, long long b, long long c, long long d) {
    long long m = min(abs(c - a), abs(d - b));
    long long p = min(abs(c - a), abs(d - b)) * 2;
    long long q;
    long long n;
    if (m == abs(c - a)) {
        n = abs(d - b) - m;

    } else if (m == abs(d - b)) {
        n = abs(c - a) - m;
    }
    if (n % 2 == 0) {
        q = 2 * n;
    } else {
        q = 2 * (n - 1) + 1;
    }
    return p + q;
}
int main() {
    long long arr[1000];
    long long brr[1000];
    long long t;
    long long a, b, c, d;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b >> c >> d;
        brr[i] = path(a, b, c, d);
    }
    for (int i = 0; i < t; i++) cout << brr[i] << endl;
}
