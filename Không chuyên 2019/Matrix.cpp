#include<bits/stdc++.h>
using namespace std;

// Khởi tạo 1 ma trận
void init(vector<vector<long long>> &v){
    for(long long i = 0; i < v.size(); i++){
        for(long long j = 0; j < v[i].size(); j++){
            cin >> v[i][j];
        }
    }
}

// In ma trận, hàm này để test chương trình
void show(vector<vector<long long>> v){
    for(auto i : v){
        for(auto j : i){
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Nhân 2 vector (nhân hàng với cột)
long long dot(vector<long long> u, vector<long long> v){
    if(u.size() != v.size()){
        return 0;
    }
    long long ans = 0;
    for(long long i = 0; i < u.size(); i++){
        ans += u[i] * v[i];
    }
    return ans;
}

// Chuyển vị ma trận để hàng biến thành cột cho dễ tính
vector<vector<long long>> transpose(vector<vector<long long>> v){
    vector<vector<long long>> u(v.size(), vector<long long>(v[0].size()));
    for(long long i = 0; i < v.size(); i++){
        for(long long j = 0; j < v[i].size(); j++){
            u[i][j] = v[j][i];
        }
    }
    return u;
}

// Nhân 2 ma trận
vector<vector<long long>> dot(vector<vector<long long>> u, vector<vector<long long>> v){
    // Chuyển vị ma trận v để dễ lấy ra 1 cột và truyền vào hàm dot
    v = transpose(v);

    // Khởi tạo vector kết quả có size là m*p (u.size = m*n, v.size = n*p)
    vector<vector<long long>> w(u.size(), vector<long long>(v[0].size()));

    for(long long i = 0; i < w.size(); i++){
        for(long long j = 0; j < w[i].size(); j++){
            // Nhân hàng với cột(hàng của ma trận chuyển vị v)
            w[i][j] = dot(u[i], v[j]);
        }
    }

    return w;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long k, n, i, j, S;
    // k: số ma trận
    // n: kích thước ma trận
    // i, j: chỉ số của phần tử cần tìm
    // S: dùng để lấy dư 
    cin >> k >> n >> i >> j >> S;

    // Khởi tạo ma trận thứ nhất để nhân
    vector<vector<long long>> u (n, vector<long long>(n));
    init(u);

    // Lấy ra vector thứ i - 1. Tương đương ma trận kích thước 1 x n
    vector<vector<long long>> w(u.begin() + i - 1, u.begin() + i);

    // Còn lại k - 1 ma trận nhân lần lượt vào u
    for(long long i = 0; i < k - 1; i++){
        // Mỗi lần chạy sẽ tạo mới ma trận cho đỡ nhầm
        vector<vector<long long>> v (n, vector<long long>(n));
        init(v);

        // Nhân 2 ma trận kích thước (1 x n) x (n x n) sẽ được ma trận (1 x n). Giảm được (n - 1)^2 lần tính toán
        w = dot(w, v);
    }

    // Tọa độ của đề bài phải trừ đi 1 mới đúng
    cout << w[0][j-1] % S;
}