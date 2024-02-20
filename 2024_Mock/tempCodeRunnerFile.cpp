#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin>>N>>K;
    int start = N-K+1;
    cout<<start;
    if (N!=1){
        cout<<" ";
    }
    for (int i = 1; i<K; i++){
        cout<<i;
        if (i+1!=K){
            cout<<' ';
        }
    }
    start = N-K+2;
    if (K>1){
        cout<<" ";
    }
    for (int i = 0; i<K-1; i++){
        cout<<start;
        if (i+1!=K-1){
            cout<<' ';
        }
        start++;
    }
}