#include <bits/stdc++.h>
using namespace std;

int main() {
    string mineral;
    cin >> mineral;
    for (int i = 0; i < mineral.length(); i++) {
        mineral[i] = tolower(mineral[i]);
    }

    int n;
    cin >> n;
    int index = 0;
    int maxMineral = int(mineral[index]) + int(mineral[index + 1]);

    for (int i = 1; i < mineral.length() - 1; i++) {
        int temp = int(mineral[i]) + int(mineral[i + 1]);
        if (temp < maxMineral) {
            index = i;
            maxMineral = temp;
        }
    }

    char minChar = max(mineral[index], mineral[index + 1]); 
    char maxChar = min(mineral[index], mineral[index + 1]);

    string answer = "";

    if (n % 2 == 0) {
        for (int i = 0; i < n / 2; i++) {
            answer = answer + maxChar + minChar;
        }
    } else {
        for (int i = 0; i < n / 2; i++) {
            answer = answer + maxChar + minChar;
        }
        answer += maxChar;
    }

    cout << answer;
}