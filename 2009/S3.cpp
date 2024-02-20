//work in progress
#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;


int bfs(vector<vector<int>>friends, bool visited[60], int depth, vector<int>next, char cmd, int find){
    bool fred = false;
    visited[next[0]] = true;
    for (int i = 0; i<next.size(); i++){
        for (int j = 0; j<friends[next[i]].size(); j++){
            if (!visited[friends[next[i]][j]]){
                next.push_back(friends[next[i]][j]);
                visited[friends[next[i]][j]] = true;
                if (friends[next[i]][j]==find){
                    fred = true;
                }
            }
        }
        next.erase(next.begin()+i);
    }
    depth+=1;
    if (cmd=='f'&&depth == 2){
        return next.size();
    }
    else if (cmd == 's'&&fred){
        return depth;
    }
    else if (cmd=='s'&&next.size()==0){
        return -1;
    }
    bfs(friends,visited,depth,next,cmd,find);
}


int main() {
    vector<vector<int>>friends;
    pii arr[]
    vector<int>empty;
    bool visited[60];
    for (int i = 0; i<60; i++){
        friends.push_back(empty);
        visited[i] = false;
    }
    vector<int>::iterator it;
    while (true){
        char q;
        int x,y;
        cin>>q;
        if (q=='q'){
            break;
        }
        else if (q=='i'){
            cin>>x>>y;
            it = find(friends[x].begin(),friends[x].end(),y);
            if (it==friends[x].end()){
                friends[x].push_back(y);
                friends[y].push_back(x);
            }
        }
        else if (q=='d'){
            cin>>x>>y;
            it = find(friends[x].begin(),friends[x].end(),y);
            friends[x].erase(it);
            it = find(friends[y].begin(),friends[y].end(),x);
            friends[y].erase(it);
        }
        else if (q=='n'){
            cin>>x;
            cout<<friends[x].size();
        }
        else if (q=='f'){
            cin>>x;
            vector<int>next;
            next.push_back(x);
            cout<<bfs(friends,visited,0,next,'f',0);
        }
        else if (q=='s'){
            cin>>x>>y;
            vector<int>next;
            next.push_back(x);
            int found = bfs(friends,visited,0,next,'s',y);
            if (found == -1){
                cout<<"Not connected";
            }
            else {
                cout<<found;
            }
        }
    }
}