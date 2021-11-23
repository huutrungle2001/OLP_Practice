#include <bits/stdc++.h>
using namespace std;

long long getTrailingZeros(long long n) {
    long long count = 0;
    while (n >= 5) {
        n /= 5;
        count += n;
    }

    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << getTrailingZeros(n) << "\n";
    }
}