#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

bool visited[3000];
bool route_visit[10000][10000];
int paint [3000][3000];

void recus (vector<int>list[10000], int node, int color){
    
}

int main() {
    int n ,r; cin>>n>>r;
    vector<int> arr[n];
    for (int i = 0; i<r; i++){
        int a,b; cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    recus()
}
