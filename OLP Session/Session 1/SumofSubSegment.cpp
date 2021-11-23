#include<iostream>
using namespace std;

int main(){
    long long n, x, q;
    cin >> n >> x >> q;

    long long arr[n + 1];
    arr[0] = 0;
    for(long long i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    long long count = 0;
    long long u, v;
    for(long long i = 0; i < q; i++) {
        cin >> u >> v;
        cout << arr[v] - arr[u] << "\n";
        if (arr[v] - arr[u - 1] < x){
            count ++;
        }
    }

    cout << count << endl;
}