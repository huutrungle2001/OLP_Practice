#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, d[1001];
    string s;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> d[i];
        cin >> s;
        if (s == "Mar") {
            if (d[i] >= 21 && d[i] <= 31)
                cout << "Aries" << endl;
            if (d[i] >= 1 && d[i] <= 20)
                cout << "Pisces" << endl;
        }
        if (s == "Apr") {
            if (d[i] >= 1 && d[i] <= 20)
                cout << "Aries" << endl;
            if (d[i] >= 21 && d[i] <= 30)
                cout << "Taurus" << endl;
        }
        if (s == "May") {
            if (d[i] >= 1 && d[i] <= 20)
                cout << "Taurus" << endl;
            if (d[i] >= 21 && d[i] <= 31)
                cout << "Gemini" << endl;
        }
        if (s == "Jun") {
            if (d[i] >= 1 && d[i] <= 21)
                cout << "Gemini" << endl;
            if (d[i] >= 22 && d[i] <= 30)
                cout << "Cancer" << endl;
        }
        if (s == "Jul") {
            if (d[i] >= 1 && d[i] <= 22)
                cout << "Cancer" << endl;
            if (d[i] >= 23 && d[i] <= 31)
                cout << "Leo" << endl;
        }
        if (s == "Aug") {
            if (d[i] >= 1 && d[i] <= 22)
                cout << "Leo" << endl;
            if (d[i] >= 23 && d[i] <= 31)
                cout << "Virgo" << endl;
        }
        if (s == "Sep") {
            if (d[i] >= 1 && d[i] <= 21)
                cout << "Virgo" << endl;
            if (d[i] >= 22 && d[i] <= 30)
                cout << "Libra" << endl;
        }
        if (s == "Oct") {
            if (d[i] >= 1 && d[i] <= 22)
                cout << "Libra" << endl;
            if (d[i] >= 23 && d[i] <= 31)
                cout << "Scorpio" << endl;
        }
        if (s == "Nov") {
            if (d[i] >= 1 && d[i] <= 22)
                cout << "Scorpio" << endl;
            if (d[i] >= 23 && d[i] <= 30)
                cout << "Sagittarius" << endl;
        }
        if (s == "Dec") {
            if (d[i] >= 1 && d[i] <= 21)
                cout << "Sagittarius" << endl;
            if (d[i] >= 22 && d[i] <= 31)
                cout << "Capricorn" << endl;
        }
        if (s == "Jan") {
            if (d[i] >= 1 && d[i] <= 20)
                cout << "Capricorn" << endl;
            if (d[i] >= 21 && d[i] <= 31)
                cout << "Aquarius" << endl;
        }
        if (s == "Feb") {
            if (d[i] >= 1 && d[i] <= 19)
                cout << "Aquarius" << endl;
            if (d[i] >= 20 && d[i] <= 29)
                cout << "Pisces" << endl;
        }
    }
    return 0;
}
