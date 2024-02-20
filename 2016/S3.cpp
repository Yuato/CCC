#include <bits/stdc++.h>

using namespace std;

vector <int> adj[1000000];

int dfs(int inx, bool n){
    vector<int>stuff;
    int main = 0;
    if (n){
        // cout<<inx<<" "<<adj[inx][0]<<'\n';
        main++;
        adj[adj[inx][0]].erase(find(adj[adj[inx][0]].begin(), adj[adj[inx][0]].end(), inx));
        adj[inx].clear();
        main += dfs(adj[inx][0], false);
    }
    while (adj[inx].size()>0){
        if (adj[inx].size()==1){
            // cout<<inx<<" "<<adj[inx][0]<<'\n';
            main++;
            if (find(adj[adj[inx][0]].begin(), adj[adj[inx][0]].end(), inx)!=adj[adj[inx][0]].end()){
                adj[adj[inx][0]].erase(find(adj[adj[inx][0]].begin(), adj[adj[inx][0]].end(), inx));
            }
            adj[inx].clear();
            main += dfs(adj[inx][0], false);
        }
        else{
            // cout<<inx<<" "<<adj[inx][0]<<'\n';
            int ind = adj[inx][0];
            adj[inx].erase(adj[inx].begin());
            main++;
            if (adj[ind].size()==2){
                main++;
                adj[ind].erase(find(adj[ind].begin(), adj[ind].end(), inx));
            }
            main += dfs(ind, false);
        }
    }
    return main;
}

void trim(int inx, int pho[]){
    if (adj[inx].size()==1&&pho[inx]==0){
        // cout<<"trim"<<inx<<'\n';
        adj[adj[inx][0]].erase(find(adj[adj[inx][0]].begin(), adj[adj[inx][0]].end(), inx));
        trim (adj[inx][0], pho);
        adj[inx].clear();
    }
}

int main() {
    int n, p;
    cin>>n>>p;
    int pho [n];
    for (int i = 0; i<n; i++){
        pho[i]=0;
    }
    for (int i = 0; i<p; i++){
        int a;
        cin>>a;
        pho[a] = 1;
    }
    for (int i = 0; i<n-1;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 0; i<n;i++){
        trim(i, pho);
    }
    int total = 0;
    for (int i = 0; i<n-1;i++){
        if (adj[i].size()==1){
            // cout<<"results";
            total = dfs(i, true);
            break;
        }
    }
    cout<<total;
}