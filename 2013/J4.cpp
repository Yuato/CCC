#include <bits/stdc++.h>

using namespace std;
 
int main() {
    int time, tasks;
    cin>>time>>tasks;
    vector<int>t;
    for (int i = 0; i<tasks; i++){
        int l; cin>>l;
        t.push_back(l);
    }
    sort(t.begin(), t.end());
    int total = 0;
    for (int i = 0; i<t.size(); i++){
        time -= t[i];
        if (time>=0){
            total++;
        }
        else{
            break;
        }
    }
    cout<<total;
}