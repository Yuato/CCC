#include <bits/stdc++.h>
#define piv pair<int,vector<int>>
// 5
// 30 1 3
// 20 0
// 10 2 4 5
// 10 0
// 10 0
using namespace std;

bool attend(int event, int curr, vector<piv>arr, vector<int>visited){
    visited.push_back(curr);
    for (int i = 0; i<visited.size(); i++){
        if (visited[i]==curr){
            return true;
        }
    }
    for (int i = 0; i<arr[curr].second.size(); i++){
        if (arr[curr].second[i]==event){
            return true;
        }
        else{
            if (attend(event,arr[curr].second[i],arr, visited)==true){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int N, T, node, event, time = 0;
    cin>>N;
    vector<piv>attends;
    vector<int>nodes;
    for (int i = 0; i < N; i++){
        cin>>T>>event;
        while (event>0){
            cin>>node;
            nodes.push_back(node-1);
            event--;
        }
        attends.push_back(pair(T,nodes));
        nodes.clear();
    }
    for (int i = 0; i<N; i++){
        if (attends[i].second.size()==0){
            time+=attends[i].first;
        }
        else if (attend(i,i,attends, nodes)==false){
            time+=attends[i].first;
        }
    }
    cout<<time;
}