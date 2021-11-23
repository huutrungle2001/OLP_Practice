#include <bits/stdc++.h>
using namespace std;

void divisor(int n, int &count, int &sum) {
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            sum += i;
            count++;
            if (i != n / i) {
                sum += n / i;   
                count++;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int l, r;
        cin >> l >> r;
        int sum = 0;
        int count = 0;
        for (int j = l; j <= r; j++) {
            divisor(j, count, sum);
        }

        cout << count << " " << sum << "\n";
    }
}
