//working (checked with DMOJ)
#include <bits/stdc++.h>
using namespace std;

string word;
char arr[100][100];

int searcher (int index, int y, int x, int y1, int x1, int dirx, int diry, int transy, int transx){
    int main = 0;
    int x2 = x;
    int y2 = y;
    for (int i = 1; i<index; i++){
        y2+=diry;
        x2+=dirx;
        if ((y2<0)||(y2>y1)||(x2<0)||(x2>x1)){
            break;
        }
        else if (word[i]!=arr[y2][x2]){
            break;
        }
        else if (i+1==index){
            main++;
            break;
        }
        for (int n = i; n<index; n++){
            if ((y2+(n-i)*transy<0)||(y2+(n-i)*transy>y1)||(x2+(n-i)*transx<0)||(x2+(n-i)*transx>x1)){
                break;
            }
            else if (word[n]!=arr[y2+(n-i)*transy][x2+(n-i)*transx]){
                break;
            }
            else if (n+1==index){
                main++;
            }
        }
        for (int n = i; n<index; n++){
            if (word[n]!=arr[y2-(n-i)*transy][x2-(n-i)*transx]){
                break;
            }
            else if ((y2-(n-i)*transy<0)||(y2-(n-i)*transy>y1)||(x2-(n-i)*transx<0)||(x2-(n-i)*transx>x1)){
                break;
            }
            else if (n+1==index){
                main++;
            }
        }
    }
    return main;
}

int solve(int index, int y, int x, int y1, int x1){
    int main = 0;
        if (y>0){
            main += searcher (index, y,x,y1,x1,0,-1,0,1);
        }
        if (y<y1){
            main += searcher (index, y,x,y1,x1, 0,1, 0, 1);
        }
        if (x>0){
            main += searcher (index, y,x,y1,x1, -1,0, 1, 0);
        }
        if (x<x1){
            main += searcher (index, y,x,y1,x1, 1,0, 1, 0);
        }
        if (x>0&&y>0){
            main += searcher (index, y,x,y1,x1, -1,-1, 1, -1);
        }
        if (x<x1&&y>0){
            main += searcher (index, y,x,y1,x1, 1, -1, 1, 1);
        }
        if (x>0&&y<y1){
            main += searcher (index, y,x,y1,x1, -1, 1, 1, 1);
        }
        if (x<x1&&y<y1){
            main += searcher (index, y,x,y1,x1, 1, 1, -1, 1);
        }
    return main;
}

int main(){
    int y, x;
    cin>>word;

    cin>>y>>x;
    for (int y1 = 0; y1<y; y1++){
        for (int x1 = 0; x1<x; x1++){
            char a;
            cin>>a;
            arr[y1][x1]=a;
        }
    }

    int total = 0;

    for (int y1 = 0; y1<y; y1++){
        for (int x1 = 0; x1<x; x1++){
            if (arr[y1][x1]==word[0]){
                total += solve(word.size(), y1, x1, y-1, x-1);
            }
        }
    }
    cout<<total;
}