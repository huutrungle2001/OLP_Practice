#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int count = (m + n) * 2 - 4;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            bool check1 = true, check2 = true, check3 = true, check4 = true;
            for (int k = 0; k < i; k++) {
                if (a[i][j] < a[k][j]) {
                    check1 = false;
                }
            }
            for (int k = i; k < n; k++) {
                if (a[i][j] < a[k][j]) {
                    check2 = false;
                }
            }
            for (int k = 0; k < j; k++) {
                if (a[i][j] < a[i][k]) {
                    check3 = false;
                }
            }
            for (int k = j; k < m; k++) {
                if (a[i][j] < a[i][k]) {
                    check4 = false;
                }
            }
            if (check1 || check2 || check3 || check4) {
                count += 1;
            }
        }
    }
    cout << count;
}