#include <bits/stdc++.h>
#define MAXM 100000
using namespace std;
long long factorial(long long n) {
    if (n == 1) {
        return 1;
    } else {
        return factorial(n - 1) * n;
    }
}
int main() {
    long long st, st_interviewed;
    long long a[MAXM], b[MAXM];
    long long count = 2, res = 0;

    cin >> st >> st_interviewed;
    for (int i = 1; i <= st_interviewed; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 2; i <= st_interviewed; i++) {
        if (a[i] == b[i - 1]) {
            count++;
        } else {
            res += factorial(count);
            cout << count << endl;
            count = 2;
        }
    }
    cout << res << endl;
}
