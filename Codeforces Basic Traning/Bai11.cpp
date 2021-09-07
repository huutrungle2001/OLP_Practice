#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n, i, j;
    cin >> n;
    int x[n][n];
    int y[n * n];
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            cin >> x[i][j];
            y[i * n + j] = x[i][j];
        }
    }
    for (i = 0; i < n * n - 1; i++){
        for (j = 0; j < n * n - 1; j++){
            if (y[j] > y[j + 1]){
                int change = y[j];
                y[j] = y[j + 1];
                y[j + 1] = change;
            }
        }
    }
    int a[n][n];
    // a) tang theo hang tu dau
    for (i = 0; i < n; i++){
        if (i % 2 == 0){
            for (j = 0; j < n; j++){
                a[i][j] = y[i * n + j];
                cout << a[i][j] << " ";
            }
            cout << endl;
        }else{
            for (j = 0; j < n; j++){
                a[i][j] = y[(i + 1) * n - j - 1];
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    // b) tang theo cot tu cuoi
    for (j = n - 1; j >= 0; j--){
        if ((n - j - 1) % 2 == 0){
            for (i = 0; i < n; i++){
                a[i][j] = y[(n - j) * n - (i + 1)];
            }
        }else{
            for (i = 0; i < n; i++){
                a[i][j] = y[(n - j - 1) * n + i];
            }
        }
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    // c) tang xoan oc tu dau
    int stt = 0, k;
    if (n % 2 != 0){
        a[(n - 1) / 2][(n - 1) / 2] = y[n * n - 1];
    }
    for (k = 0; k < n / 2; k++){
        i = k;
        for (j = k; j < n - k; j++){
            a[i][j] = y[stt];
            stt++;
        }
        j = n - k - 1;
        for (i = k + 1; i < n - k; i++){
            a[i][j] = y[stt];
            stt++;
        }
        i = n - k - 1;
        for (j = n - 2 - k; j >= k; j--){
            a[i][j] = y[stt];
            stt++;
        }
        j = k;
        for (i = n - 2 - k; i >= k + 1; i--){
            a[i][j] = y[stt];
            stt++;
        }
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    // d) zic zac
    stt = 0;
    for (k = 0; k <= 2 * n - 2; k++){
        if (k % 2 != 0){
            for (i = max(0, k - n + 1); i <= min(k, n - 1); i++){
                a[i][k - i] = y[stt];
                stt++;
            }
        }else{
            for (i = max(0, k - n + 1); i <= min(k, n - 1); i++){
                a[k - i][i] = y[stt];
                stt++;
            }
        }
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}