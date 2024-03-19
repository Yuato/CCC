#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;cin>>n;
    long long arr[n];
    for (int i = 0; i<n; i++){
        long long a; cin>>a;
        arr[i] = a;
    }
    int count = 0;
    for (int i = 0; i<n/2; i++){
        if (arr[i]==arr[n/2+i]){
            count+=2;
        }
    }
    cout<<count;
    cout<<(int)'a'-46;
    return 0;
}