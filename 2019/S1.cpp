#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin>>str;
    int V = 0, H = 0;
    int arr[2][2];
    int chg[2][2];
    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[1][0] = 3;
    arr[1][1] = 4;
    for (int i = 0; i<str.size(); i++){
        char tran = str[i];
        if (tran == 'V'){
            V++;
        }
        else{
            H++;
        }
    }
    if (V%2==1&&H%2==1){
        chg[0][0] = 4;
        chg[0][1] = 3;
        chg[1][0] = 2;
        chg[1][1] = 1;
    }
    else if (V%2==1&&H%2==0){
        chg[0][0] = 2;
        chg[0][1] = 1;
        chg[1][0] = 4;
        chg[1][1] = 3;
    }
    else if (V%2==0&&H%2==1){
        chg[0][0] = 3;
        chg[0][1] = 4;
        chg[1][0] = 1;
        chg[1][1] = 2;
    }
    else{
        chg[0][0] = 1;
        chg[0][1] = 2;
        chg[1][0] = 3;
        chg[1][1] = 4;
    }
    for (int i = 0; i<2; i++){
        for (int j = 0; j<2; j++){
            cout<<chg[i][j];
            if (j+1!=2){
                cout<<' ';
            }
        }
        if (i+1!=2){
            cout<<'\n';
        }
    }
}