// #include<bits/stdc++.h>
// using namespace std;

// bool isRichNumber(int n){
//     if(n < 12) return 0;
//     int temp = 1;
//     for (int i = 2; i <= sqrt(n); i++) {
//         if(n % i == 0){
//             temp = (i != n/i) ? (temp + i + n/i) : (temp + i);
//             if(temp > n){
//                 return 1;
//             }
//         }
//     }
//     return 0;
// }



// int main(){
//     int l, r, count = 0;
//     cin >> l >> r;
//     for(int i = l; i <= r; i++) {
//         if(isRichNumber(i)){
//             count ++;
//         }
//     }

//     cout << count;
// }
#include<stdio.h>
#include<math.h>
int isRichNumber(int n){
    if(n < 12){
        return 0;
    }
    int temp = 1;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            temp += i;
            if(i != n/i){
                temp += n/i;
            }
        }     
        if (temp > n){
            return 1;
        }     
    }
    return 0;
}
 
int main() {
    int a, b,count = 0;
    scanf("%d%d", &a, &b);
    for(int i = a; i <= b; i++) {
       if(isRichNumber(i)){
        count++;
       }                      
    }
    printf("%d",count); 
    return 0;
}