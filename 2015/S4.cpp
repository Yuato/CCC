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
#define pii pair<long long, long long>

using namespace std;

int main() {
    int K, N, M;
    cin>>K>>N>>M;
    vector<vector<int>>routes;
    vector<vector<pii>>stats;
    vector<int>empty;
    vector<pii>empty2;
    for (int i = 0;i<N+1; i++){
        routes.push_back(empty);
        stats.push_back(empty2);
    }
    for (int i = 0; i<M; i++){
        long long a, b, t, d;
        cin>>a>>b>>t>>d;
        routes[a].push_back(b);
        stats[a].push_back(pair(t,d));
        routes[b].push_back(a);
        stats[b].push_back(pair(t,d));
    }
    long long arr[N+1][K];
    bool visited[N+1][K];
    for (int i = 0; i<N+1;i++){
        for (int j = 0; j<K; j++){
            arr[i][j] = INT64_MAX;
            visited[i][j]= true;
        }
    }
    long long start, end;
    cin>>start>>end;

    arr[start][0] = 0;
    priority_queue<pii, vector<pii>, greater<pii>>pq_node;
    priority_queue<pii, vector<pii>, greater<pii>>pq_hull;
    pq_node.push(pair(0,start));
    pq_hull.push(pair(0,0));
    while (!pq_node.empty()){
        long long time = pq_node.top().first;
        long long node = pq_node.top().second;
        long long hull = pq_hull.top().second;
        pq_node.pop();
        pq_hull.pop();
        if (visited[node][hull]){
            arr[node][hull] = time;
            visited[node][hull] = false;
            for (int j = 0; j<routes[node].size(); j++){
                int n_hull = hull+stats[node][j].second;
                if (n_hull<K&&visited[routes[node][j]][n_hull]){
                    pq_node.push(pair(time+stats[node][j].first,routes[node][j]));
                    pq_hull.push(pair(time+stats[node][j].first,n_hull));
                }
            }
        }
        if (node == end){
            break;
        }
    }
    long long min = INT64_MAX;
    for (int i = 0; i<K; i++){
        if (arr[end][i]<min){
            min = arr[end][i];
        }
    }
    if (min!=INT64_MAX){
        cout<<min;
    }
    else{
        cout<<-1;
    }
}