//working (checked with DMOJ)
#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int main() {
    int r,c;cin>>r>>c;
    vector<pii>next;
    char arr[r][c];
    bool visited [r][c];
    for (int i = 0; i<r; i++){
        for (int j = 0; j<c; j++){
            char a; cin>>a;
            arr[i][j] =a;
            visited[i][j] = false;
        }
    }
    int x, y; cin>>x>>y;
    next.push_back(pair(x,y));
    int tot = 0;
    while (next.size()!=0){
        int row = next[0].first;
        int col = next[0].second;
        next.erase(next.begin());
        if (visited[row][col]==false&&arr[row][col]!='*'&&row>=0&&row<r&&col>=0&&col<c){
            visited[row][col] = true;
            next.push_back(pair(row+1,col));
            next.push_back(pair(row-1,col));
            next.push_back(pair(row,col+1));
            next.push_back(pair(row,col-1));
            if (arr[row][col] == 'S') tot+=1;
            else if (arr[row][col] == 'M') tot+=5;
            if (arr[row][col] == 'L') tot+=10;
        }
    }
    cout<<tot;
    return 0;
}