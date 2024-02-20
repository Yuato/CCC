#include <bits/stdc++.h>

using namespace std;

int main (){
    cin.tie(nullptr) -> sync_with_stdio(0);

    int G, P, n, total = 0;
    cin>>G>>P;
    set<int>gates;
    for (int i = 0; i<G+1; i++){
        gates.insert(i);
    }
    std::set<int>::iterator it;
    while (P>0){
        cin>>n;
        it = gates.lower_bound(n);
        if (it!=gates.begin()){
            gates.erase(--it);
            total++;
        }
        else break;
        P--;
    }
    cout<<total;
    return 0;
}