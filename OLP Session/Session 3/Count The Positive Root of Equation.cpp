#include <bits/stdc++.h>
using namespace std;

bool isInt(double x) {
    return x - int(x) == 0 ? 1 : 0;
}

int main() {
    int q;
    cin >> q;
    long long a, b, c;
    for (int i = 0; i < q; i++) {
        cin >> a >> b >> c;

        double x1 = (1 - b) * 1.0 / a;
        double x2 = (-1 - b) * 1.0 / a;

        if (c == 0) {
            cout << "oo\n";
        } else {
            if (c % 2 == 0) {
                if (a == 0 && (b == 1 || b == -1)) {
                    cout << "oo\n";
                    continue;
                }
                cout << (isInt(x1) + isInt(x2)) << "\n";
            } else {
                if (a == 0 && b == 1) {
                    cout << "oo\n";
                    continue;
                }
                cout << isInt(x1) << "\n";
            }
        }
    }
}
