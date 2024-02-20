#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[100];
    for (int i = 0; i<100; i++){
        arr[i]=0;
    }
    int doll;
    cin>>doll;
    for (int i = 0; i<doll; i++){
        int a;
        cin>>a;
        arr[a] = arr[a]+1;
    }
    int max = 0;
    int max_p, min_p;
    int min = INT32_MAX;
    for (int i = 0; i<100; i++){
        if (arr[i]>max){
            max = arr[i];
            max_p = i;
        }
        if (arr[i]<min){
            min = arr[i];
            min_p = i;
        }
    }
    cout<<max_p-min_p;
}