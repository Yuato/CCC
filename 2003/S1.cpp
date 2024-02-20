//working (checked with DMOJ)
#include <bits/stdc++.h>

using namespace std;

int board(int position, int m){
    int p = position+m;
    if (p == 99){
        p=77;
    }
    else if ( p == 90){
        p=48;
    }
    else if (p == 54){
        p = 19;
    }
    else if (p == 67){
        p = 86;
    }
    else if (p == 40){
        p = 64;
    }
    else if (p == 9){
        p = 34;
    }
    else if (p>100){
        p = position;
    }
    return p;
}

int main(){
    int p = 1, m;
    while (cin>>m){
        p = board(p, m);
        if (m!=0){
            cout<<"You are now on square "<<p<<'\n';
        }
        if (p ==100){
            cout<<"You Win!";
            win = true;
            break;
        }
        else if (m == 0){
            cout<<"You Quit!";
            break;
        }
    }
}