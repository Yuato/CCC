//work in progress

// 10 4 7
// 1 2 4 4
// 1 3 7 2
// 3 1 8 1
// 3 2 2 2
// 4 2 1 6
// 3 4 1 1
// 1 4 6 12
// 1 4
#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int main() {
    int K, N, M;
    cin>>K>>N>>M;
    vector<vector<int>>routes;
    vector<vector<pii>>stats;
    vector<int>next;
    vector<int>empty;
    vector<pii>empty2;
    for (int i = 0;i<N+1; i++){
        routes.push_back(empty);
        stats.push_back(empty2);
    }
    for (int i = 0; i<M; i++){
        int a, b, t, d;
        cin>>a>>b>>t>>d;
        routes[a].push_back(b);
        stats[a].push_back(pair(t,d));
        routes[b].push_back(a);
        stats[b].push_back(pair(t,d));
    }
    int start, end;
    cin>>start>>end;
    next.push_back(start);
    int arr[N+1][K];
    int visited[N+1]; 
    for (int i = 0; i<N+1; i++){
        visited[i] = 0;
        for (int j = 0; j<K; j++){
            arr[i][j] = 0;
        }
    }
    visited[start] = 1;
    arr[start][0] = 1;
    bool poss = false;
    while (next.size()>0){
        for (int i = 0; i<routes[next[0]].size(); i++){
            for (int j = 0; j<K; j++){
                if (arr[next[0]][j]!=0&&stats[next[0]][i].second+j<K){
                    arr[routes[next[0]][i]][stats[next[0]][i].second+j] = arr[next[0]][j]+stats[next[0]][i].first;
                    if (routes[next[0]][i]==end){
                        poss = true;
                    }
                }
            }
            if (visited[routes[next[0]][i]]==0){
                next.push_back(routes[next[0]][i]);
                visited[routes[next[0]][i]]=1;
            }
        }
        next.erase(next.begin());
    }
    if (poss){
        int min = INT32_MAX;
        for (int i = 0; i<K; i++){
            if (arr[end][i]!=0&&arr[end][i]<min){
                min = arr[end][i];
            }
        }
        cout<<min-1;
    }
    else cout<<-1;
}