#include<iostream>
using namespace std;
int main(){
    int n, k, answer = 0, center, x, y;
    cin >> n >> k;
    center = n/2 + 1;
    for(int i = 0; i < k; i++){
        cin >> x >> y;
        answer += min(abs(center-x), abs(center-y))*15 + abs(abs(center-x) - abs(center-y))*10;
    }
    cout << answer;
}