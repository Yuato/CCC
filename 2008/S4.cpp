//work in progress
#include <bits/stdc++.h>

using namespace std;

int solve (vector<int>list){
    vector<int>nex;
    int length = list.size();
    if (length == 1){
        return list[0];
    }
    else {
        for (int i = 0; i <length; i++){
            for (int n = i+1; n<length; n++){
                for (int m = 0; m<length; m++){
                    if (m!=n&&m!=i){
                        nex.push_back(list[m]);
                    }
                }
                nex.push_back(list[i]+list[n]);
                int solve(nex);
                nex.clear();
            }
        }
    }
}

int main(){
    cout<<"exited";
}