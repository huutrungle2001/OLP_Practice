#include<iostream>
using namespace std;

int main(){
    long long a, b;
    cin >> a >> b;
    if(a % 3 == 0){
        cout << (b/3) - (a/3) + 1;
    }else{
        cout << (b/3) - (a/3);
    }
}