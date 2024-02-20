#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin>>a>>b;
    vector<int>sumac;
    sumac.push_back(a);
    sumac.push_back(b);
    int total = 2;
    while(sumac[sumac.size()-1]<=sumac[sumac.size()-2]){
        sumac.push_back(sumac[sumac.size()-2]-sumac[sumac.size()-1]);
        if (sumac[sumac.size()-1]<0){
            break;
        }
        total++;
    }
    cout<<total;
}