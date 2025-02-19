#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    long long arr[n+10][n+10];
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            long long a; cin>>a;
            arr[i][j] = a;
        }
    }
    
    int i = 0;
    int j = 0;

    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j--){
            long long a; cin>>a;
            arr[i][j] = a;
        }
    }

    while (true){
        
    }
}