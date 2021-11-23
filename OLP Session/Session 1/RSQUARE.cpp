//credit: minhvd @ phenikaa

#include <bits/stdc++.h>
using namespace std;

int N, giao = 0, namtrong = 0;

bool outside(int x, int y, double R) {
    return (x * x + y * y) > R * R;
}

bool inside(int x, int y, double R) {
    return !outside(x, y, R);
}

bool intersect(int x, int y, double R) {
    bool isOutside = outside(x, y + 1, R);
    bool isInside = inside(x - 1, y, R);
    return isInside && isOutside;
}

void xuly() {
    giao = namtrong = 0;
    cin >> N;
    if (N == 0) {
        cout << "0 0" << endl;
        return;
    }
    for (int y = 0; y < N; y++) {
        int x = (int)(sqrt(N * N - N + 0.25 - y * y) + 1); // (x,y) nằm ngoài đường tròn, (x-1,y) nằm trong đường tròn
        //(x,y) là góc trái dưới
        while (intersect(x, y, N - 0.5) && x > 0) {
            giao++;
            x--;
        }
        namtrong += x;
    }
    cout << 4 * giao << " " << 4 * namtrong << endl;
}

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        xuly();
    }
    return 0;
}