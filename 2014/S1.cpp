#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, m;
    cin>>n>>m;
    vector<int>ppl;
    for (int i = 1; i<=n; i++){
        ppl.push_back(i);
    }
    vector<int>clear;
    while (m>0){
        clear.clear();
        int r;
        cin>>r;
        for (int i = r-1; i<ppl.size(); i+=r){
            clear.push_back(i);
        }
        for (int i = 0; i<clear.size(); i++){
            ppl.erase(ppl.begin() + clear[i]-i);
        }
        m--;
    }
    for (int i = 0; i<ppl.size(); i++){
            cout<<ppl[i];
            if (i+1!=ppl.size()){
                cout<<'\n';
            }
        }
}