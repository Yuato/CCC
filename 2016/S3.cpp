//Question reattempt
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>>adj;

int main() {
    int n, m;
    cin>>n,m;
    int pho [n+1];
    for (int i = 0; i<n+1; i++){
        adj.push_back(vector<int>);
        pho = 1;
    }
    for (int i= 0; i<m; i++){
        int x; cin>>x;
        pho[x] = 0;
    }
    
    for (int i = 0 ;i<n-1; i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0 ;i<n-1; i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}