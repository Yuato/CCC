#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>stuff;
    bool pal = false;
    while (true){
        n++;
        int m = n;
        while (m>0){
            if (find(stuff.begin(),stuff.end(),m%10)!=stuff.end()){
                break;
            }
            stuff.push_back(m%10);
            m = m/10;
            if (m==0){
                pal = true;
                break;
            }
        }
        stuff.clear();
        if (pal){
            break;
        }
    }
    cout<<n;
}