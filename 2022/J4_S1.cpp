#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num;
    int count = 0;
    int holder = num;
    cin>>num;
    int limit = num/4;
    for (int i = 0; i<limit+1;i++){
        holder = num;
        holder = holder-(i*4);
        if (holder%5==0){
            count++;
        }
    }
    cout<<count;
    return 0;
}
