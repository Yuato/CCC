//solved (checked with DMOJ)
//Implementation storing each possible patterns are possible each row in a set
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<set<vector<int>>>lights (33);
    int R, L; cin>>R>>L;
    vector<int>change(L);
    int arr[R+1][L+1];

    for (int i = 0; i<R; i++){
        for (int j = 0; j<L; j++){
            int a; cin>>a;  
            change[j] = a;
            arr[i][j] = a;
        }
        lights[i].insert(change);
    }

    for (int i = 0; i < R-1; i ++){
        for (auto j : lights[i]){
            for(int z = 0; z < j.size(); z ++){
                if (j[z]==arr[i+1][z]){
                    change[z] = 0;
                }
                else change[z] = 1;
            }
            lights[i+1].insert(change);
        }
    }
    cout<<lights[R-1].size();
}