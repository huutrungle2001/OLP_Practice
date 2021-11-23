// #include <bits/stdc++.h>
// using namespace std;

// #define MAX 100000007

// long long factorial(int n) {
//     if (n < 2) {
//         return 1;
//     }

//     long long answer = 1;
//     for (int i = 2; i <= n; i++) {
//         answer = (answer * i);
//     }

//     return answer;
// }

// long long C(int k, int n) {
//     return ((factorial(n) % MAX) /factorial(k))/factorial(n - k);
// }

// void PascalTriangle(int n){
//     for(int i = 0; i <= n; i++){
//         cout << C(i, n) << " ";
//     }
//     cout << "\n";
// }

// int main() {
//     // int t, n;
//     // cin >> t;
//     // for (int i = 0; i < t; i++) {
//     //     cin >> n;
//     //     PascalTriangle(n);
//     // }

//     // cout << C(3, 15);
//     cout << factorial(15)/factorial(7)/factorial(8);
// }
/* ID : itperday.com
LANG : C++
PROG : itperday.com
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 100000007
vector<unsigned long long> pas(2, 1);
int len, i;
void inPascal(int n) {
    len = pas.size();
    while (n--) {
        for (i = 0; i < len / 2; ++i) {
            pas[i + 1] = pas[i + 1] + pas[len - i - 1];
            pas[len - i - 1] = pas[i + 1];
        }
        pas.push_back(1);
        len = pas.size();
        /* Uncomment this block below to print full Pascal triangle */

        // for (i = 0; i < len; i++)
        //     cout << pas[i] << " ";
        // cout << endl;
    }
    /*Just print the last line only*/
    len = pas.size();
    for (i = 0; i < len; i++)
        cout << pas[i] % MAX << " ";
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        inPascal(n - 1);
    }
}