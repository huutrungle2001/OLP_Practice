#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<int> a;
    vector<int> b;
    for(int i=0; i<s.length(); i++){
        a.push_back(int(s[i]) - 48);
        b.push_back(int(s[i]) - 48);
    }
    sort(a.begin(), a.end());   
    // // for(int i=0; i<b.size(); i++) {
    // //     while(find(b.begin(), b.end(), a.end()) != b.end() && n > 0){
    // //         b.erase(find(b.begin(), b.end(), a.end()));
    // //         n --;
    // //     }
    // // }
    while (n > 0){
        if(find(b.begin(), b.end(), a.back()) != b.end()){
            b.erase(find(b.begin(), b.end(), a.back()));
            n --;
        }else{
            a.pop_back();
        }
    }
    for(auto i : b){
        cout << i;
    }
}