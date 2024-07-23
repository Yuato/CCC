//Solved (Checked with DMOJ 7/23/2024)
//Solution: BFS
#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

bool visited [100][100];
char arr [100][100];

int bfs(vector<pii> coords, int row, int col, int count){
    vector<pii>next;
    int i = 0;
    while( i<coords.size()){
        int cr = coords[i].first;
        int cc = coords[i].second;
        if (cr>row||cr<0){
            i++;
        }
        else if (cc>col||cc<0||visited[cr][cc]==true){
            i++;
        }
        else if (arr[cr][cc] == '*'){
            i++;
        }
        else if (cr==row&&cc==col){
            return count;
        }
        else if (arr[cr][cc]=='+'){
            visited[cr][cc]=true;
            next.push_back(pair(cr+1,cc));
            next.push_back(pair(cr-1,cc));
            next.push_back(pair(cr,cc+1));
            next.push_back(pair(cr,cc-1));
            i++;
        }
        else if (arr[cr][cc]=='|'){
            visited[cr][cc]=true;
            next.push_back(pair(cr+1,cc));
            next.push_back(pair(cr-1,cc));
            i++;
        }
        else if (arr[cr][cc] == '-'){
            visited[cr][cc]=true;
            next.push_back(pair(cr,cc+1));
            next.push_back(pair(cr,cc-1));
            i++;
        }
        else{
            i++;
        }
    }
    if (next.size()==0){
        return -1;
    }
    count+=1;
    return bfs(next, row, col, count);
}

int main() {
    int t; cin>>t;
    for (int i = 0; i<t; i++){
        int r, c;cin>>r>>c; 
        for (int x = 0; x<r; x++){
            for (int y = 0; y<c; y++){
                char a; cin>>a;
                visited[x][y] = false;
                arr[x][y] = a;
            }
        }
        vector<pii>coords;
        coords.push_back(pair(0,0));
        int num = bfs(coords, r-1, c-1, 1);
        cout<<num<<'\n';
    }
}