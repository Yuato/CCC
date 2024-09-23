//Solved (checked with DMOJ)
//solution: Recursion

#include <bits/stdc++.h>

using namespace std;

bool solve (int l, int m, long long x, long long y){
    if (l>m){
        return false;
    }
    long long mod = 5;
    if (l>=2){
        mod = pow(5,l-1);
    }
    long long nx = (long long)(x/pow(5,(m-l)))%mod;
    long long ny =(long long)(y/pow(5,(m-l)))%mod;
    if (nx==1||nx==3){
        if (ny==0){
            return true;
        }
        else if(ny==1){
            return solve (l+1,m,x,y);
        }
    }
    else if (nx==2){
        if (ny<2){
            return true;
        }
        else if(ny==2){
            return solve (l+1,m,x,y);
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,t;
    long long x,y;
    cin>>t;
    for (int i = 0 ;i<t; i++){
        cin>>m>>x>>y;
        if(solve(1,m,x,y))cout<<"crystal";
        else cout<<"empty";
        cout<<'\n';
    }
}