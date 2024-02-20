//work in progress
#include <bits/stdc++.h>
#define piv pair<int,vector<int>>
// 5
// 30 1 3
// 20 0
// 10 2 4 5
// 10 0
// 10 0
using namespace std;

int main(){
    int N, T, node, event, time = 0, max = 0;
    cin>>N;
    vector<piv>attends;
    vector<int>nodes;
    vector<int>visited;
    vector<int>times_max;
    std::vector<int>::iterator it;
    int dp[N];
    for (int i = 0; i < N; i++){
        cin>>T>>event;
        while (event>0){
            cin>>node;
            nodes.push_back(node-1);
            event--;
        }
        if (event ==0 ){
            dp[i] = T;
            if (T>max){
                max = T;
            }
        }
        else {
            dp[i] = -1;
        }
        attends.push_back(pair(T,nodes));
        nodes.clear();
    }
    for (int i = 0; i<N; i ++){
        if (dp[i]==-1){
            nodes.push_back(i);
        }
        while (nodes.size()>0){
            attends
            visited.push_back(nodes[0]);
        }
    }
   
}