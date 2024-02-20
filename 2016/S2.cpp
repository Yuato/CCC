#include <bits/stdc++.h>

using namespace std;

int max(int a, int b){
    return a>b ? a:b;
}

int main() {
    int q, n;
    cin>>q>>n;
    vector<int>dmoj;
    vector<int>peg;
    for (int i = 0; i<n; i++){
        int l;
        cin>>l;
        dmoj.push_back(l);
    }
    for (int i = 0; i<n; i++){
        int l;
        cin>>l;
        peg.push_back(l);
    }
    sort(dmoj.begin(), dmoj.end());
    sort(peg.begin(), peg.end());
    int total = 0;
    if (q == 1){
        for (int i = 0; i<n; i++){
            total += max(dmoj[i], peg[i]);
        }
    }
    else{
        for (int i = 0; i<n; i++){
            total += max(dmoj[i], peg[n-1-i]);
        }
    }
    cout<<total;
}