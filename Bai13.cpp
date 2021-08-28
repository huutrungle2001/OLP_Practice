#include<iostream>
using namespace std;



int main(){
    int x = 0, y = 0, n, dir = 1;
    cin >> n;
    string s;
    cin >> s;
    for(char c : s){
        switch(dir){
            case 1:
                switch(c){
                    case 'G':
                        y += 1;
                        break;
                    case 'L':
                        x -= 1;
                        dir = 4;
                        break;
                    case 'R':
                        x += 1;
                        dir = 2;
                        break;
                    case 'B':
                        y -= 1;
                        dir = 3;
                        break;
                }
                break;
            case 2:
                switch(c){
                    case 'G':
                        x += 1;
                        dir = 2;
                        break;
                    case 'L':
                        y += 1;
                        dir = 1;
                        break;
                    case 'R':
                        y -= 1;
                        dir = 3;
                        break;
                    case 'B':
                        x -= 1;
                        dir = 4;
                        break;
                }
                break;
            case 3:
                switch(c){
                    case 'G':
                        y -= 1;
                        dir = 3;
                        break;
                    case 'L':
                        x += 1;
                        dir = 2;
                        break;
                    case 'R':
                        x -= 1;
                        dir = 4;
                        break;
                    case 'B':
                        y += 1;
                        dir = 1;
                        break;
                }
                break;
            case 4:
                switch(c){
                    case 'G':
                        x -= 1;
                        dir = 4;
                        break;
                    case 'L':
                        y -= 1;
                        dir = 3;
                        break;
                    case 'R':
                        y += 1;
                        dir = 1;
                        break;
                    case 'B':
                        x += 1;
                        dir = 2;
                        break;
                }
                break;
        }
    }
    cout << x << " " << y << endl;
}