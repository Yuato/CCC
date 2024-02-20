#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, low;
    bool odd = false;
    cin>>n;
    vector<int>tide;
    for (int i = 0; i<n; i++){
        int a; cin>>a;
        tide.push_back(a);
    }
    sort(tide.begin(), tide.end());
    if (n%2==1){
        n--;
        odd = true;
        low = tide[0];
        tide.erase(tide.begin());
    }
    for (int i = 0; i<n/2;i++){
        cout<<tide[n/2-1-i]<<" "<< tide[n/2+i];
        if (i+1!=n/2){
            cout<<" ";
        }
    }
    if (odd){
        cout<<" "<<low;
    }
}