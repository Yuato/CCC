#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin>>N>>K;
    int start = N-K+1;//3

    if (K>0){
        cout<<start;
        for (int i = 1; i<=start-1; i++){
            cout<<" "<<i;
        }
        cout<<" ";
    }

    for (int i = N-K+2; i<=N; i++){
        cout<<i;
        if (i+1<=N){
            cout<<' ';
        }
    }
}