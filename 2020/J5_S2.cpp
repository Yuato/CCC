//working (checked with DMOJ)
#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;
// 3
// 4
// 3 10 8 14
// 1 11 12 12
// 6 2 3 9

int main(){
    bool poss = false;
    int N, M;
    cin>>N>>M;
    int arr [N][M];
    vector<vector<pii>>adj(1000010);
    for (int i = 0; i<N; i++){
        for (int j = 0; j<M; j++){
            int a;
            cin>>a;
            arr[i][j] = a;
            adj[(i+1)*(j+1)].push_back(pair(i,j));
        }
    }
    std::vector<int>::iterator it;
        
    vector<int>next;
    int count = 0;
    int size = 1;
    next.push_back(arr[0][0]);
    while (count < size){
        for (int i = 0; i<adj[next[count]].size(); i++){
            if (adj[next[count]][i].first==N-1&&adj[next[count]][i].second==M-1){
                poss=true;
                break;
            }
            next.push_back(arr[adj[next[count]][i].first][adj[next[count]][i].second]);
            size++;
        }
        adj[next[count]].clear();
        count++;
        if (poss){
            break;
        }
        
    }
    if (poss){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
}
