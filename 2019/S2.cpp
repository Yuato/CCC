//working (checked with DMOJ)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int r = 2000000;
    int arr[r];
    vector<int>primes;
    for (int i = 2; i<r; i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2 ;i<r; i++){
        if (arr[i]==0){
            primes.push_back(i);
            for (int j = 2; j<=(r-1)/i; j++){
                arr[i*j] = 1;
            }
        }
    }
    int n; 
    cin>>n;
    for (int i= 0; i<n; i++){
        int num;
        cin>>num;
        num = num*2;
        for (int i = 0; i<primes.size(); i++){
            if (num-primes[i]<r&&num-primes[i]>0&&arr[num-primes[i]]==0){
                cout<<primes[i]<<" "<<num-primes[i];
                break;
            }
        }
        if (i+1!=n){
            cout<<'\n';
        }
    }
}