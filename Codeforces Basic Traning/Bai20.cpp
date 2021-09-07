#include<bits/stdc++.h>
using namespace std;

struct Circle{
    int x, y, r;

    void input(){
        cin >> x >> y >> r;
    }

    bool intersect(Circle c){
        return sqrt(pow(c.x - x, 2) + pow(c.y - y, 2)) < (c.r + r) ? true : false;
    }
};

int main(){
    int n, count = 0;
    cin >> n;
    Circle c[n];
    for(int i = 0; i < n; i++){
        c[i].input();
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++){
            if(c[i].intersect(c[j])){
                count ++;
            }
        }
    }
    cout << count;
}