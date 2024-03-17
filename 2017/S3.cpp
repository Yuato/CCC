#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin>>n;
    int arr [10000];
    while (n>0){
        int i; cin>>i;
        arr[i] +=1;
        n--;
    }
    int count = 0;
    int sum [10000];
    for (int i = 0; i<2001; i++){
        for (int j = i; j<2001; j++){
            if (arr[i]==0){
                break;
            }
            else if (j==i){
                sum[i*2]+=arr[i]/2;
            }
            else if (arr[j]>arr[i]){
                sum[i+j] += arr[i];
            }
            else {
                sum[i+j] += arr[j];
            }
        }
    }
    int max = 0;
    for (int i = 0; i<4001; i++){
        if (sum[i]>0&&sum[i]==max){
            count++;
        }
        if (sum[i]>max){
            max = sum[i];
            count = 1;
        }
    }
    cout<<max<<" "<<count;
}