#include <bits/stdc++.h>

using namespace std;
// 2
// 4
// 2
// 3
// 1
// 4
// 4
// 4
// 1
// 3
// 2
int main() {
    int t;
    cin>>t;
    vector<int>top;
    vector<int>branch;
    while (t>0){
        int n; cin>>n;
        int count = 1;
        for (int i = 0; i<n; i++){
            int a; cin>>a;
            top.push_back(a);
        }
        for (int i = 1; i<=n; i++){
            if (branch.size()>0&&branch[branch.size()-1]==i){
                branch.pop_back();
            }
            else{
                while (top.size()>0&&top[top.size()-1]!=i){
                    branch.push_back(top[top.size()-1]);
                    top.pop_back();
                }
                if (top.size()>0&&top[top.size()-1]==i){
                    top.pop_back();
                }
            }
        }
        if (top.size()>0||branch.size()>0){
            cout<<'N';
        }
        else{
            cout<<'Y';
        }
        t--;
        top.clear();
        branch.clear();
        if (t!=0){
            cout<<'\n';
        }
    }
}