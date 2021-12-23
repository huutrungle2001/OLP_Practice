#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;

    void input(){
        cin >> x >> y;
    }

    bool isEqualDistance(Point other){
        return (x == other.x || y == other.y);
    }
};

int main(){
    int n;
    cin >> n;
    vector<Point> points;
    int count = 0;
    for(int i = 0; i < n; i++){
        Point temp;
        temp.input();
        points.push_back(temp);
        for(Point point : points){
            if(point.isEqualDistance(temp)){
                count++;
            }
        }
    }

    // Trừ đi n điểm trùng lúc duyệt
    cout << count - n;
}