#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
    void input(){
        cin >> x >> y;
    }
};

float distance(Point p1, Point p2){
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

bool isOptuse(float a, float b, float c){
    return (a*a > b*b + c*c || b*b > a*a + c*c || c*c > a*a + b*b) ? true : false;
}   

float S(float a, float b, float c){
    float p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

float R(Point p1, Point p2, Point p3){
    float a = distance(p1, p2);
    float b = distance(p2, p3);
    float c = distance(p3, p1);

    return isOptuse(a,b,c) ? max(max(a,b),c)/2 : a*b*c/(4*S(a,b,c));
}

Point p[101];

int main(){
    int n;  
    cin >> n;
    for(int i = 0; i < n; i++){
        p[i].input();
    }

    float minR = INT_MIN;

    for(int i = 0; i < n - 2; i++){
        for(int j = i + 1; j < n - 1; j++){
            for(int k = j + 1; k < n; k++){
                minR = max(minR, R(p[i], p[j], p[k]));
            }
        }
    }
    printf("%.3f", minR);
}