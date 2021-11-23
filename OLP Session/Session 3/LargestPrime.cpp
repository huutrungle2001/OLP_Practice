#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n < 2){
        return false;
    }

    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }

    return true;
}

int main(){
    int n;
    cin >> n;
    int LargestPrime = INT_MIN;
    unordered_map<int, vector<int>> hashTable;
    for(int i = 1; i <= n; i++){
        int temp;
        cin >> temp;
        LargestPrime = isPrime(temp) ? max(LargestPrime, temp) : LargestPrime;
        hashTable[temp].push_back(i);
    }

    cout << LargestPrime << "\n";
    for(int i : hashTable[LargestPrime]){
        cout << i << " ";
    }
}