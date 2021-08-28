#include<iostream>
using namespace std;

void On(){
    int n;
    cin >> n;
    int a[n];
    double max_avg = INT_MIN, min_avg = INT_MAX;
    for(int i = 0; i < n; i++){
        double sum = 0;
        cin >> a[i];
        if(i != 0){
            sum = a[i] + a[i-1];
            max_avg = max(max_avg, sum/2);
            min_avg = min(min_avg, sum/2);
        }
    }   
    printf("%.3f %.3f\n", min_avg, max_avg);
}

void On3(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    double max_avg = INT_MIN, min_avg = INT_MAX;

    for(int i = 0; i < n; i++){
        // j = i + 2; sub array length must be at least 2;
        for(int j = i + 2; j <= n; j++){
            double sum = 0;
            // Get sum from a[i] to a[j]
            for(int k = i; k < j; k++){
                sum += a[k];
            }
            max_avg = max(max_avg, sum/(j - i));
            min_avg = min(min_avg, sum/(j - i));
        }
    }
    
    printf("%.3f %.3f\n", min_avg, max_avg);
}

void On3_ver2(){
    int n;
    cin >> n;
    float max_avg = INT_MIN, min_avg = INT_MAX;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < n - i + 1; j++){
            float sum = 0;
            for(int k = j; k < i + j; k++){
                sum += a[k];    
            }
            max_avg = max(max_avg, sum/i);
            min_avg = min(min_avg, sum/i);
        }
    }
    printf("%.3f %.3f", min_avg, max_avg);
}

int main(){
    return 0;
}