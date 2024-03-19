#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[3][n];
    for (int i = 0; i<n; i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[0][i] = a;
        arr[1][i] = b;
        arr[2][i] = c;
    }    
    int m; 
    cin>>m;
    int total = 0;
    for (int i = 0; i<m; i++){
        int min = INT32_MAX;
        bool poss = false;
        int a,b,c;
        cin>>a>>b>>c;
        for (int j = 0; j<n; j++){
            if (arr[0][j]>=a&&arr[1][j]>=b&&arr[2][j]>=c&&arr[0][j]*arr[1][j]*arr[2][j]<min){
                poss = true;
                min = arr[0][j]*arr[1][j]*arr[2][j];
            }
            else if (arr[0][j]>=a&&arr[2][j]>=b&&arr[1][j]>=c&&arr[0][j]*arr[1][j]*arr[2][j]<min){
                poss = true;
                min = arr[0][j]*arr[1][j]*arr[2][j];
            }
            else if (arr[1][j]>=a&&arr[0][j]>=b&&arr[2][j]>=c&&arr[0][j]*arr[1][j]*arr[2][j]<min){
                poss = true;
                min = arr[0][j]*arr[1][j]*arr[2][j];
            }
            else if (arr[1][j]>=a&&arr[2][j]>=b&&arr[0][j]>=c&&arr[0][j]*arr[1][j]*arr[2][j]<min){
                poss = true;
                min = arr[0][j]*arr[1][j]*arr[2][j];
            }
            else if (arr[2][j]>=a&&arr[0][j]>=b&&arr[1][j]>=c&&arr[0][j]*arr[1][j]*arr[2][j]<min){
                poss = true;
                min = arr[0][j]*arr[1][j]*arr[2][j];
            }
            else if (arr[2][j]>=a&&arr[1][j]>=b&&arr[0][j]>=c&&arr[0][j]*arr[1][j]*arr[2][j]<min){
                poss = true;
                min = arr[0][j]*arr[1][j]*arr[2][j];
            }
        }
        if (poss){
            cout<<min;
        }
        else{
            cout<<"Item does not fit.";
        }
        if (i+1!=m){
            cout<<'\n';
        }
    }
}