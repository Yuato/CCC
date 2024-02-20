#include <bits/stdc++.h>

using namespace std;

int main() {
    int depth, depth2, depth3, depth4;
    cin>>depth>>depth2>>depth3>>depth4;

    if (depth>depth2 && depth2>depth3 && depth3>depth4) cout<<"Fish Diving";
    else if (depth<depth2 && depth2<depth3 && depth3<depth4) cout<<"Fish Rising";
    else if (depth==depth2 && depth2==depth3 && depth3==depth4) cout<<"Fish At Constant Depth";
    else cout<<"No Fish";

    return 0;
}