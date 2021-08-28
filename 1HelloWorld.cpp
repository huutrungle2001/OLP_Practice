#include <iostream>
using namespace std;

int main() {
	int T, N, Q, L, R;
	cin >> T;
	for(int i = 0; i < T; i++){
	    cin >> N >> Q;
	    int a[N];
	    for(int j = 0; j < N; j++){
	        cin >> a[j];
	    }
	    for(int j = 0; j < Q; j++){
	        cin >> L >> R;
	        int count = 0;
	        for(int k = L - 1; k <= R - 1; k++){
	            if(a[k] % 5 == 0){
	                count ++;
	            }
	        }
	        cout << count << " ";
	    }
	    cout << endl;
	}
}