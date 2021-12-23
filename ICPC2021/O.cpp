#include <bits/stdc++.h>
#define N 200005
using namespace std;
int n;
long long res = 0;

struct state {
    int x, y;
} c[N];

map<int, long long> mp;
map<int, long long> mp2;
map<pair<int, int>, long long> mp3;
set<pair<int, int>> s;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i].x >> c[i].y;
        mp[c[i].x]++;
        mp2[c[i].y]++;
        mp3[{c[i].x, c[i].y}]++;
    }
    for (auto x : mp) {
        long long t = x.second;
        res += t * (t - 1) / 2;
    }
    for (auto y : mp2) {
        long long t = y.second;
        res += t * (t - 1) / 2;
    }
    for (auto z : mp3) {
        long long t = z.second;
        res -= t * (t - 1) / 2;
    }
    cout << res << "\n";
    return 0;
}