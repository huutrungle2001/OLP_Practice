#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    map<int, int> mp;

    for(int i = 1; i <= n; i++){
        int tmp;
        cin >> tmp;
        auto it = mp.find(x - tmp);
        if (it != mp.end()) {
            return cout << it->second << " " << i, 0;
        }else{
            mp[tmp] = i;
        }
    }

    cout << "IMPOSSIBLE";
}