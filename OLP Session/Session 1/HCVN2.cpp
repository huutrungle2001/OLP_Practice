#include<bits/stdc++.h>
using namespace std;

struct Rectangle {
    long long X_left, X_right, Y_top, Y_bot;

    // Empty constructor
    Rectangle(){
        long long X1, Y1, X2, Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;
        X_left = min(X1, X2);
        X_right = max(X1, X2);
        Y_bot = min(Y1, Y2);
        Y_top = max(Y1, Y2);
    }

    // Construct a Rectangle from two given polong longs
    Rectangle(long long X1, long long Y1, long long X2, long long Y2){
        X_left = min(X1, X2);
        X_right = max(X1, X2);
        Y_bot = min(Y1, Y2);
        Y_top = max(Y1, Y2);
    }

    Rectangle Intersect(Rectangle other){
        // If [a,b] doesn't long longersect [c,d] we have b < c || d < a.
        if(Y_top < other.Y_bot || other.Y_top < Y_bot || X_right < other.X_left || other.X_right < X_left){
            return {0,0,0,0};
        }

        X_left = max(X_left, other.X_left);
        X_right = min(X_right, other.X_right);
        Y_bot = max(Y_bot, other.Y_bot);
        Y_top = min(Y_top, other.Y_top);

        Rectangle result = Rectangle(X_left, Y_bot, X_right, Y_top);
        return result;
    }

    long long S(){
        return (X_right - X_left) * (Y_top - Y_bot);
    }
};

int main(){
    Rectangle R1 = Rectangle();
    Rectangle R2 = Rectangle();    
    cout << R1.Intersect(R2).S();
}