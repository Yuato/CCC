//working (checked with DMOJ)
#include <bits/stdc++.h>

using namespace std;

vector<int>rooms;
int r,c;
bool visited[100][100];
char arr [100][100];

int flood(int row, int col){
    int size = 0;
    if (row>=0&&row<r&&col>=0&&col<c&&visited[row][col]!=true){
        visited[row][col] = true;
        if (arr[row][col] == '.'){
            size++;
        }
        else{
            return size;
        }
        size+=flood(row+1,col);
        size+=flood(row-1,col);
        size+=flood(row,col-1);
        size+=flood(row,col+1);
    }
    return size;
}

int main() {
    int wood, count = 0;
    cin>>wood>>r>>c;
    
    for (int i = 0; i <r; i++){
        for (int j = 0; j<c; j++){
            char a;
            cin>>a;
            arr[i][j] = a;
            visited[i][j] = false;
        }
    }
    for (int i = 0; i <r; i++){
        for (int j = 0; j<c; j++){
            int size = 0;
            if (visited[i][j]!=true&&arr[i][j]=='.'){
                size = flood(i,j);
                rooms.push_back(size);
            }
            
        }
    }
    sort(rooms.begin(), rooms.end());
    for (int i = rooms.size()-1; i>=0; i--){
        if (wood>=rooms[i]){
            wood-=rooms[i];
            count++;
        }
        else{
            break;
        }
    }
    cout<<count<<" room";
    if (count!=1){
        cout<<"s";
    }
    cout<<", "<<wood<<" square metre(s) left over";
}