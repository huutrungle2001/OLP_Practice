#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    float a, b, c;
    for (int i = 0; i < q; i++) {
        cin >> a >> b >> c;
        if (c == 0) {
            cout << "oo\n";
        } else {
            if ((int)c % 2 == 0) {
                if (((1 - b) / a) - (int)((1 - b) / a) == 0) {
                    cout << "2\n";
                } else {
                    cout << "0\n";
                }
            } else {
                if (((1 - b) / a) - (int)((1 - b) / a) == 0) {
                    cout << "1\n";
                } else {
                    cout << "0\n";
                }
            }
        }
    }
}