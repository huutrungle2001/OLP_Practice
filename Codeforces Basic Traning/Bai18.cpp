#include <bits/stdc++.h>
using namespace std;

int arr[201][201];

void mark(int arr[201][201], int x_start, int y_start, int x_end, int y_end) {
    for (int x = x_start; x < x_end; x++) {
        for (int y = y_start; y < y_end; y++) {
            arr[x][y] = 1;
        }
    }
}

int sum(int arr[201][201]) {
    int answer = 0;
    for (int i = 0; i < 201; i++) {
        for (int j = 0; j < 201; j++) {
            answer += arr[i][j];
        }
    }
    return answer;
}

int main() {
    int n, x_start, y_start, x_end, y_end;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x_start >> y_start >> x_end >> y_end;
        x_start += 100;
        y_start += 100;
        x_end += 100;
        y_end += 100;
        mark(arr, x_start, y_start, x_end, y_end);
    }

    cout << sum(arr);
}