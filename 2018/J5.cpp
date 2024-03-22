//work in progress
//solution: BFS and track pages visited, track shortest too

#include <bits/stdc++.h>

using namespace std;

bool visited[10010];
int arr [10010];

void bfs(vector<vector<int>>pages,vector<int>next, int step){
    vector<int>hold;
    for (int i = 0; i<next.size(); i++){
        if (pages[next[i]].size()==0){
            arr[next[i]] = step;
        }
        else{
            arr[next[i]] = 10000;
        }
        if (visited[next[i]]==false){
            visited[next[i]] = true;
            for (int j = 0; j<pages[next[i]].size(); j++){
                hold.push_back(pages[next[i]][j]);
            }
        }
    }
    if (hold.size()!=0){
        bfs(pages, hold, step+1);
    }
}

int main() {
    vector<vector<int>>pages;
    vector<int>link;
    pages.push_back(link);
    for (int i = 0; i<10010; i++){
        visited[i] = false;
    }
    
    int n; cin>>n;
    for (int i = 0; i <n; i++){
        link.clear();
        int num; cin>>num;
        for (int j = 0; j<num; j++){
            int l; cin>>l;
            link.push_back(l);
        }
        pages.push_back(link);
    }
    vector<int>next;
    next.push_back(1);
    bfs(pages, next, 1);

    int min = 10000;
    bool poss = true;
    for (int i = 1; i<n+1; i++){
        if (arr[i]<min){
            min = arr[i];
        }
        if (visited[i]==false){
            poss = false;
        }
    }
    if (poss){
        cout<<'Y';
    }
    else{
        cout<<'N';
    }
    cout<<'\n'<<min;
}