//work in progress
#include <bits/stdc++.h>

using namespace std;

int main() {
    int arr[26][26];
    int R,C;
    cin>>R>>C;
    for (int i = 0 ; i<26; i++){
        for (int j = 0 ; j<26; j++){
            arr[i][j]=1;
        }
    }
    int cats, x, y;
    cin>>cats;
    while (cats>0){
        cin>>x>>y;
        arr[x][y]=0;
        cats--;
    }
    for (int i = 1; i<=R; i++){
        for (int j = 1; j<=C; j++){
            if (i==1&&j==1){
                j++;
            }
            if (arr[i][j]!=0&&i==1){
                arr[i][j] = arr[i][j-1];
            }
            else if (arr[i][j]!=0&&j==1){
                arr[i][j] = arr[i-1][j];
            }
            else if (arr[i][j]!=0){
                arr[i][j] = arr[i-1][j]+arr[i][j-1];
            }
        }
    }
    cout<<arr[R][C];
}