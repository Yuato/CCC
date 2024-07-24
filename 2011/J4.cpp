//Solved (checked with DMOJ)
//notes: pain in the arse
#include <bits/stdc++.h>
#define pci pair<char,int>

using namespace std;

int main(){
    vector<pci>plan;
    plan.push_back(pair('d',2));
    plan.push_back(pair('r',3));
    plan.push_back(pair('d',2));
    plan.push_back(pair('r',2));
    plan.push_back(pair('u',2));
    plan.push_back(pair('r',2));
    plan.push_back(pair('d',4));
    plan.push_back(pair('l',8));
    plan.push_back(pair('u',2));
    bool grid[404][404];
    for (int i = 0; i<404; i++){
        for (int j = 0; j<404; j++){
            grid[i][j] = false;
        }
    }
    grid[202][202-1] = true;
    char cmd;
    int units;
    bool safe = true;
    int x = 202;
    int y = 202-1;
    int i = 0;
    while (true){
        if (i<=8){
            cmd=plan[i].first;
            units = plan[i].second;
            
        }
        else{
            cin>>cmd>>units;
        }
        if (cmd=='q'){
            return 0;
        }
        else if (cmd=='l'){
            for (int i = 1; i<=units; i++){
                if (grid[x-i][y]==true){
                    safe = false;
                }
                grid[x-i][y] = true;
            }
            x = x-units;
        }
        else if (cmd=='d'){
            for (int i = 1; i<=units; i++){
                if (grid[x][y-i]==true){
                    safe = false;
                }
                grid[x][y-i] = true;
            }
            y = y-units;
        }
        else if (cmd=='r'){
            for (int i = 1; i<=units; i++){
                if (grid[x+i][y]==true){
                    safe = false;
                }
                grid[x+i][y] = true;
            }
            x = x+units;
        }
        else if (cmd=='u'){
            for (int i = 1; i<=units; i++){
                if (grid[x][y+i]==true){
                    safe = false;
                }
                grid[x][y+i] = true;
            }
            y = y+units;
        }
        if (i>=9){
            cout<<x-202<<" "<<y-202;
            if (safe){
                cout<<" safe";
            }
            else{
                cout<<" DANGER";
                return 0;
            }
            cout<<'\n';
        }
        
        
        i++;
    }
}