#include <bits/stdc++.h>

using namespace std;
const int MAXN = 255;
int dp[MAXN][MAXN][MAXN];

int recus(int prev, int ppl, int pies){
    int count = 0;
    if (ppl == 0){
        return 1;
    }
    if(dp[prev][ppl][pies] != 0) return dp[prev][ppl][pies]; 
    for (int i = prev; i<=(pies/ppl); i++){
        count += recus(i,ppl-1,pies-i);
        if (ppl == 1){
            break;
        }
    }
    dp[prev][ppl][pies] = count;

    return count;
}

int main() {
    int N, K;
    cin>>N>>K;
    int count=0;
    count += recus(1,K,N);
    cout<<count;
}