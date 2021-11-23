#include <bits/stdc++.h>
using namespace std;

int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                bool condition1 = abs(arr[i] - arr[j]) <= a;
                bool condition2 = abs(arr[j] - arr[k]) <= b;
                bool condition3 = abs(arr[i] - arr[k]) <= c;
                if (condition1 && condition2 && condition3) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    cout << "Hello";
}