#include<bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
    double distance(point p){
        return sqrt(pow(p.x - x,2) + pow(p.y - y,2));
    };
    void set(){
        cin >> x >> y;
    }
    void show(){
        cout << "(x,y) = {" << x << "," << y << "}" << endl; 
    }
};

int main(){
    int n;
    cin >> n;
    point p[n];
    for(int i = 0; i < n; i++){
        p[i].set();
    }
    double d[n];
    double min = INT_MAX;
    int index;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            d[i] += p[i].distance(p[j]);
        }
        if(d[i] < min){
            min = d[i];
            index = i + 1;
        }
    }
    printf("%d %.3f", index, min);
}