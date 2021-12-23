#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000007

int main() {
    int n;
    cin >> n;
    vector<long long> zero;
    long long product = 1;
    long long maxNegative = LLONG_MIN;
    long long minPositive = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        long long temp;
        cin >> temp;
        if (temp == 0) {
            zero.push_back(0);
        } else {
            if (temp > 0) {
                minPositive = min(minPositive, temp);
            } else {
                maxNegative = max(maxNegative, temp);
            }
            temp %= MAX;
            product = (product * temp) % MAX;
        }
    }

    if (zero.size() > 1) {
        product = 0;
    } else if (product < 0) {
        maxNegative %= MAX;
            product = (product / maxNegative);
    }

    cout << product << endl;
}


