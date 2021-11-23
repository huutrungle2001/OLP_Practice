#include<bits/stdc++.h>
using namespace std;

int getGCD(multiset<int> ms){
    int result = *ms.begin();
    for(int i : ms){
        result = __gcd(result, i);
    }

    return result;
}

int main(){
    int n;
    cin >> n;
    multiset<int> ms;
    for(int i = 0; i < n; i++){
        int op;
        cin >> op;
        if(op == 1){
            int is;
            cin >> is;
            ms.insert(is);
            cout << getGCD(ms) << "\n";
        }else{
            int rm;
            cin >> rm;
            ms.erase(ms.find(rm));
            cout << getGCD(ms) << "\n";
        }
    }
}