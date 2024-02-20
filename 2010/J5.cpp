//working (checked with DMOJ)

#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int main() {
    int y,x,x1,y1;
    bool poss = false;
    cin>>y>>x>>y1>>x1;
    int arr[8][8];
    vector<vector<pii>>atk;
    vector<pii>first;
    first.push_back(pair(y,x));
    atk.push_back(first);
    for (int y = 0; y<8; y++){
        for (int x = 0; x<8; x++){
            arr[y][x] = 0;
        }
    }
    vector<pii>next;
    while (true){
        for (int i = 0; i<atk[atk.size()-1].size(); i++){
            int disy = atk[atk.size()-1][i].first;
            int disx = atk[atk.size()-1][i].second;
            if (disy ==y1 && disx == x1){
                poss = true;
                break;
            }
            if (disy+2<=8&&disx+1<=8&&arr[disy+2-1][disx+1-1]==0){
                next.push_back(pair(disy+2,disx+1));
                arr[disy+2-1][disx+1-1]=1;
            }
            if (disy+2<=8&&disx-1>=1&&arr[disy+2-1][disx-1-1]==0){
                next.push_back(pair(disy+2,disx-1));
                arr[disy+2-1][disx-1-1]=1;
            }
            if (disy-2>=1&&disx+1<=8&&arr[disy-2-1][disx+1-1]==0){
                next.push_back(pair(disy-2,disx+1));
                arr[disy-2-1][disx+1-1]=1;
            }
            if (disy-2>=1&&disx-1>=1&&arr[disy-2-1][disx-1-1]==0){
                next.push_back(pair(disy-2,disx-1));
                arr[disy-2-1][disx-1-1]=1;
            }
            if (disy+1<=8&&disx+2<=8&&arr[disy+1-1][disx+2-1]==0){
                next.push_back(pair(disy+1,disx+2));
                arr[disy+1-1][disx+2-1]=1;
            }
            if (disy+1<=8&&disx-2>=1&&arr[disy+1-1][disx-2-1]==0){
                next.push_back(pair(disy+1,disx-2));
                arr[disy+1-1][disx-2-1]=1;
            }
            if (disy-1>=1&&disx+2<=8&&arr[disy-1-1][disx+2-1]==0){
                next.push_back(pair(disy-1,disx+2));
                arr[disy-1-1][disx+2-1]=1;
            }
            if (disy-1>=1&&disx-2<=8&&arr[disy-1-1][disx-2-1]==0){
                next.push_back(pair(disy-1,disx-2));
                arr[disy-1-1][disx-2-1]=1;
            }
        }
        atk.push_back(next);
        next.clear();
        if (poss){
            break;
        }
    }
    cout<<atk.size()-2;
}