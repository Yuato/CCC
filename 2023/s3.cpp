#include <bits/stdc++.h>

using namespace std;

int change(int x, int y) {

}

int main() {
    bool poss = true;
    int y,x, R,C;
    cin>>y>>x>>R>>C;
    char arr[y][x];
    for (int y1=0; y1<y; y1++){
        for (int x1 = 0; x1<x; x1++){
            arr[y1][x1]= 'a';
        }
    }
    int nonrow = y-R;
    int noncol = x-C;
    if (nonrow%2==1&&y%2==0){
        if (noncol==0){
            poss = false;
        }
        else{
            for (int i = 0; i<nonrow; i++){
                arr[0][i] += 1;
            }
        }
    }
    else{
        
    }
}

