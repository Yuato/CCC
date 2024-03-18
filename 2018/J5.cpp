//work in progress
//solution: BFS and track pages visited, track shortest too

#include <bits/stdc++.h>

using namespace std;

bool visited[10010];
vector<vector<int>>pages;
static int min = 10000;

void bfs(vector<int>next, int step){
    vector<int>hold;
    for (int i = 0; i<next.size(); i++){
        if (step<min&&pages[next[i]].size()==0){
            min = step;
        }
        if (visited[next[i]]==false){
            visited[next[i]] = true;
            for (int j = 0; j<pages[next[i]].size(); j++){
                hold.push_back(pages[next[i]][j]);
            }
        }
    }
    if (hold.size()!=0){
        bfs(hold, step+1);
    }
}

int main() {
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
    bfs(next, 1);
}