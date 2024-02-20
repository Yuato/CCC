//work in progress
#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M, C, L;
    cin>>N>>M>>C;
    if (N>M){
        L = N;
    }
    else L=M;
    int arr[L][2];
    for (int i = 0; i<L; i++){
        arr[i][0]=0;
        arr[i][1]= 0;
    }

    while (C>0){
        int affect;
        char s;
        cin>>s>>affect;
        if (s=='R'){
            arr[affect-1][0]+=1;
        }
        else{
            arr[affect-1][1]+=1;
        }
        C--;
    }
    int count = 0;
    for (int i = 0; i<N; i++){
        for (int j = 0; j<M; j++){
            int hold = arr[i][0]+arr[j][1];
            if (hold%2==1){
                count++;
            }
        }
    }
    cout<<count;
}