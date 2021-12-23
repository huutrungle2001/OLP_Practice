#include<bits/stdc++.h>
// Có n người tham gia Squid game phiên bản cơ sở bí mật
// Mỗi người chơi chọn 1 vị trí trong kg 1 chiều
// Có một sát thủ
// Những người chơi và sát thủ có thể di chuyển 1m/s
// Nhưng chỉ 1 người chơi có thể di chuyển trong 1 lần
// Nếu sát thủ và bất kỳ người chơi nào ở một vị
// trí trong 1 thời điểm những người đó sẽ bị loại bỏ
// Có một nơi trú ẩn có thể chứa bất kỳ số lượng người chơi nào
// nhưng sát thủ sẽ ko bỏ qua. Nếu bất kì người chơi đến 
// đó và ko có sát thủ ở đó, họ an toàn.
// Bạn biết đồ thị và vị trí tất cả người chơi và sất thủ
// Bạn cần tìm số lượng người chơi lớn nhất đc an toàn
// n <= 10^5
// Dòng đầu là toạ độ người chơi
// Tiếp theo là toạ độ sát thủ
// Tiếp theo là toạ độ shelter
#define N 100005
using namespace std;

int n;
long long res = 0;
long long x[N];
long long y, z;

bool cmp(long long a, long long b){
    return (abs(a-z) < abs(b-z)) || (abs(a-z) == abs(b-z) && abs(a-y) > abs(b-y));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i];
    }
    cin >> y >> z;
    sort(x+1,x+n+1, cmp);
    long long c = abs(y-z);
    int ind = 1;
    while( c > 0 ){
        if( c > abs(z-x[ind]) && ind <= n){
            c -= abs(z-x[ind]);
            ind++;
            res++;
        }else{
            break;
        }
    }
    cout << res << "\n";
    return 0;
}