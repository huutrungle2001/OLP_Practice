#include <bits/stdc++.h>

using namespace std;
int a, h;
double res;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> h;
    (cout << fixed).precision(8);
    res = 200.0 * h / 3;
    int x = h / 6;
    int x1 = (ceil)(h * 1.0 / 6);
    cout << x1 << "\n";
    int y = h / 3;
    for (int i = 1; i <= h / 3; i++) {
        if (i <= x) {
            res = max(res, 1.0 * a * i * (h - i) / x);
        } else {
            res = max(res, ((100 - a) * i - 100.0 * x1 + y * a) * (h - i) / (y - x1));
        }
    }
    cout << res << "\n";
    return 0;
}