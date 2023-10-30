#include <bits/stdc++.h>

using namespace std;

int main()
{
    int plays = 0;
    int machine = 0;
    int coins, mac1, mac2, mac3;
    cin>>coins>>mac1>>mac2>>mac3;
    int arr1[3] = {mac1,mac2,mac3};

    while (coins!=0){
        coins=coins-1;
        plays++;
        machine = ((plays-1)%3);
        arr1[machine]=arr1[machine]+1;

        if (arr1[0]!=0){
        if (arr1[0]%35==0){
            coins+=30;
            arr1[0]=0;
        }
    }
        if (arr1[1]!=0){
        if (arr1[1]%100==0){
            coins+=60;
            arr1[1]=0;
        }
    }
        if (arr1[2]!=0){
        if (arr1[2]%10==0){
            coins+=9;
            arr1[2]=0;
        }
        }
    }
    cout<<"Martha plays "<<plays<<" times before going broke.";
}