#include <bits/stdc++.h>
using namespace std;

int char2int(char c) {
    return c - '0';
}

int sumDigit(long long n) {
    string s = to_string(n);
    int answer = 0;
    for (char c : s) {
        answer += char2int(c);
    }

    return answer;
}

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

bool isSpecial(long long n) {
    return isPrime(sumDigit(n));
}

int main() {
    long long n;
    string s;
    cin >> n;

    int count = 0;

    for (int i = 0; i <= n; i++) {
        int y = (n - i) / 2;
        if (isSpecial(i) && isSpecial(y) && (i + 2 * y == n)) {
            count++;
        }
    }

    cout << count;
}