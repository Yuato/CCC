//solved (checked with DMOJ)
//Dijkstra algorithm with the inital nodes being nodes that sell pencils (filter through a priority queue)
#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, T, P;
    cin>>N>>T;
    vector<pii> arr[N+1];
    bool visited[N+1];
    int costed[N+1];
    for (int i = 1; i<N+1; i++){
        visited[i] = false;
        costed[i] = 0;
    }
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    for (int i = 0; i<T; i++){
        int x,y,c;
        cin>>x>>y>>c;
        arr[x].push_back({y,c});
        arr[y].push_back({x,c});
    }
    cin>>P;
    for (int i = 0; i<P; i++){
        int x, c;
        cin>>x>>c;
        pq.push({c,x});
    }
    int fnode; cin>>fnode;
    while (!pq.empty()){
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if (!visited[node]){
            costed[node] = cost;
            visited[node] = true;
        }
        for (int i=0; i<arr[node].size();i++){
            if (!visited[arr[node][i].first]){
                pq.push({arr[node][i].second+cost,arr[node][i].first});
            }
        }
        if (node == fnode){
            break;
        }  
    }
    
    cout<<costed[fnode];
}