//working (checked with DMOJ)
#include <bits/stdc++.h>

using namespace std;

int main() {
    bool good = true;
    int num; cin>>num;
    string first[num];
    string Sec[num];
    for (int i = 0; i<num; i++){
        string input; cin>>input;
        first[i] = input;
    }
    for (int i = 0; i<num; i++){
        string input; cin>>input;
        Sec[i] = input;
    }
    for (int i = 0; i<num; i++){
        string f, s;
        f = first[i];
        s = Sec[i];
        for (int j = i+1; j<num; j++){
            if (first[j]==s&&Sec[j]!=f){
                good = false;
                break;
            }
        }
        if (f==s) good = false;
        if (!good){
            break;
        }
    }
    if (good){
        cout<<"good";
    }
    else{
        cout<<"bad";
    }
}