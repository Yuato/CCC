//working (checked with DMOJ)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int arr[100];
    for (int i = 0; i<100; i++){
        arr[i] = 0;
    }
    int n; cin>>n;
    for (int i = 0; i<n; i++){
        int a; cin>>a;
        arr[a]+=1;
    }
    int freq = 0; int min=1;
    for (int i = 0; i<100; i++){
        if (arr[i]>freq){
            freq = arr[i];
            min = i;
        }
    }
    cout<<min<<'\n';
}