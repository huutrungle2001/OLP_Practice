#include <bits/stdc++.h>
#define MOD (long long)1000000007
using namespace std;

int t;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> s;
        int l = s.size();
        if (l == 1) {
            cout << (s[0] == '1') << "\n";
            continue;
        }
        int cnt = (s[0] == '1') + (s[l - 1] == '1');
        for (int i = 1; i < l - 1; i++) {
            if (s[i] == '1') {
                if (s[i - 1] == '0' || (i + 1 < l && s[i + 1] == '0')) {
                    continue;
                } else {
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}