//work in progress
#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int ret = 0;


void bfs(vector<vector<int>>friends, bool visited[60], int depth, vector<int>next, char cmd, int find){
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
        ret = next.size();
    }
    else if (cmd == 's'&&fred){
        ret = depth;
    }
    else if (cmd=='s'&&next.size()==0){
        ret = -1;
    }
    else if (next.size()!=0){
        bfs(friends,visited,depth,next,cmd,find);
    }
}


int main() {
    int arr1[] = {2,1,7,5,4,3,3,5,5,7,8,9,9,10,11,15,12,15,14,16,17,17};
    int arr2[] = {6,6,6,6,6,6,4,4,3,8,9,10,12,11,12,3,13,13,13,18,18,16};
    vector<vector<int>>friends;
    for (int i = 0; i<sizeof(arr1); i++){
        friends[arr1[i]].push_back(arr2[i]);
        friends[arr2[i]].push_back(arr1[i]);
    }
    cout<<"hello";
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
            bfs(friends,visited,0,next,'f',0);
            cout<<ret;
        }
        else if (q=='s'){
            cin>>x>>y;
            vector<int>next;
            next.push_back(x);
            bfs(friends,visited,0,next,'s',y);
            if (ret == -1){
                cout<<"Not connected";
            }
            else {
                cout<<ret;
            }
        }
    }
}