#include<bits/stdc++.h>
using namespace std;

float y(long long x, float x1, float y1, float x2, float y2){
    return ((x - x1) * (y2 - y1)) / (x2 - x1) + y1;
}

void duyet(){
    float x1, y1, x2, y2, count = 0;
    cin >> x1 >> y1 >> x2 >> y2;
    for(long long x = x1 + 1; x < x2; x++){
        if(y(x, x1, y1, x2, y2) - (long long)y(x, x1, y1, x2, y2) == 0){
            count ++;
        }
    }

    cout << count;
}
 
int main(){
    int m, n, p, q;
    cin >> m >> n >> p >> q;
    cout << __gcd(abs(m - p), abs(n - q)) - 1;
}