#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n), B(n), C;
    for (int i = 0; i < n; i++){
        A[i] = i + 1;
        cin >> B[i];
    }
    for(int i = 0; i < n; i++){
        C.insert(C.begin(), A[A.size() - B.back() - 1]);
        A.erase(A.begin() + A.size() - B.back() - 1);
        B.erase(B.begin() + B.size() - 1);
    }

    for(auto i : C){
        cout << i << " ";
    }
}