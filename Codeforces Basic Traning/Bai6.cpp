#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, s, k, pos = 0;
    cin >> n;
    vector<int> JosephusA, JosephusB;
    for(int i = 1; i <= n; i++){
        JosephusA.push_back(i);
        JosephusB.insert(JosephusB.begin(), i);
    }
    cin >> s;
    while(JosephusA.size() > 1){
        // printf("JosephusA size: %d\n", JosephusA.size());
        // printf("Position: %d\n", pos);
        JosephusA.erase(JosephusA.begin() + (pos + s - 1)%JosephusA.size());
        pos = (pos + s - 1)%(JosephusA.size() + 1);
        // cout << "After deleting:\n";
        // for(auto i : JosephusA){
        //     cout << i << " ";
        // }
        // cout << "\n";
    }
    cin >> k;
    pos = JosephusB.size() - k;
    while(JosephusB.size() > 1){
        // printf("JosephusB size: %d\n", JosephusB.size());
        // printf("Position: %d\n", pos);
        JosephusB.erase(JosephusB.begin() + (pos + s - 1)%JosephusB.size());
        pos = (pos + s - 1)%(JosephusB.size() + 1);
        // cout << "After deleting:\n";
        // for(auto i : JosephusB){
        //     cout << i << " ";
        // }
        // cout << "\n";
    }
    cout << JosephusA.at(0) << "\n" << JosephusB.at(0);
}