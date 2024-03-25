//WA (needs review)
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr[10000];
    bool visited[10000];
    priority_queue<int> pq;
    int dp[n+1];
    for (int i = 0; i<n+1; i++){
        dp[i] = 0;
        visited[i] = false;
    }
    dp[1] = 1;
    while (true){
        int a,b;cin>>a>>b;
        if (a == 0 && b== 0) break;
        else{
            arr[a].push_back(b);
        }
    }
    pq.push(1);
    while (pq.size()!=0){
        int next = pq.top();
        pq.pop();
        if (visited[next]==false){
            visited[next] = true;
            for (int i = 0; i<arr[next].size(); i++){
                pq.push(arr[next][i]);
                dp[arr[next][i]]+=dp[next];
            }
        }
    }
    cout<<dp[n];
}