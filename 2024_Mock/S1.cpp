//work in progress

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, ava;
    string marbles;
    cin>>N>>ava>>marbles;
    int arr[N];
    int sep[N];
    for (int i = 0; i<N; i++){
        sep[i] = 0;
        arr[i] = 1;
        if (i+1<N){
            if (marbles[i]=='1'&&marbles[i+1]=='1'){
                arr[i] = 0;
            }
        }
        if (marbles[i]=='0'){
            arr[i] = 0;
        }
    }
    int dis = 0;
    bool one = false;

    for (int i = 0; i<N; i++){
        if (one&&arr[i]==0){
            dis+=1;
        }
        if (one&&arr[i]==1){
            sep[dis] +=1;
            dis = 0;
        }
        if (arr[i]==1){
            one = true;
        }
        
    }

    for (int i = 0; i<N; i++){
        while (ava>0&&sep[i]>0){
            if (ava>=i){
                ava-=i;
                sep[i]-=1;
            }
            else{
                ava = 0;
            }
        }
        if (ava<i){
            break;
        }
    }
    int total = 0;
    for (int i = 0; i<N; i++){
        total += sep[i];
    } 
    if (total>0||ava>0){
        total +=1;
    }
    cout<<total;
}