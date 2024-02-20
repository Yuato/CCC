//work in progress
#include <bits/stdc++.h>

using namespace std;

int main() {
    int arr[4] = {1,2,0,0};
    int times[720];
    int mins=720;
    int count = 0;
    bool arith = true;
    while (mins>0){
        arr[3]+=1;
        if (arr[3]==10){
            arr[3]=0;
            arr[2]=arr[2]+1;
        }
        if (arr[2]==6){
            arr[2]=0;
            arr[1]+=1;
        }
        if (arr[0]*10+arr[1]==13){
            arr[1]=1;
            arr[0]=0;
        }
        if (arr[1]==10){
            arr[1]=0;
            arr[0]=1;
        }
        int diff = arr[1]-arr[0];
        if (arr[0]==0){
            diff = arr[2]-arr[1];
        }
        for (int i = 1; i<3; i++){
            if (arr[i+1]-arr[i]!=diff){
                arith = false;
                break;
            }
        }
        
        mins--;

        if (arith){
            count++;
            times[720-mins-1] = count+1;
        }
        else{
            times[720-mins-1] = count;
        }
        arith = true;
    }
    long long minutes;
    cin>>minutes;
    int loops = minutes/720;
    int total = loops*count+times[(minutes%720)];
    cout<<total;
}