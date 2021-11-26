#include <bits/stdc++.h>
using namespace std;

// Get sum from start, reset sum when smaller than current sum (get increase only)
void KadaneAlgorithms() {
    int n;
    cin >> n;

    long long max_so_far = INT_MIN;
    long long max_here = 0;
    long long arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        max_here = max(max_here + arr[i], arr[i]);
        max_so_far = max(max_so_far, max_here);
    }

    cout << max_so_far;
}

// S[i] = sum(1...i)
// answer = max(S[i] - S[j]) with j < i and S[j] is min
void Prefix() {
    long long n;
    cin >> n;
    long long S = 0;
    long long maxSub = LLONG_MIN;
    long long minSub = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        S += temp;
        maxSub = max(maxSub, S - minSub);
        minSub = min(minSub, S);
    }

    cout << maxSub;
}

// DP, halve the array, get max on the left, on the right and crossing midpoint



int main() {
    // KadaneAlgorithms();
    Prefix();
}