#include<bits/stdc++.h>
using namespace std;

struct Patient{
    int arrival, duration;
    void input(){
        cin >> arrival >> duration;
    }
};

bool Patientcpr(Patient p1, Patient p2){
    return p1.arrival < p2.arrival;
}

int main(){
    int n, timestamp = 0;
    cin >> n;
    Patient p[n];
    for(int i = 0; i < n; i++){
        p[i].input();
    }
    sort(p, p + n, Patientcpr);
    for(int i = 0; i < n; i++){
        timestamp = max(timestamp, p[i].arrival) + p[i].duration;
    }

    cout << timestamp;
}