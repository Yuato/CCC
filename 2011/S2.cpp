//working (checked with DMOJ)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int num; cin>>num;
    char ans [num];
    char stud [num];
    for (int i = 0; i<num; i++){
        char lol; cin>>lol;
        stud[i] = lol;
    }
    for (int i = 0; i<num; i++){
        char lol; cin>>lol;
        ans[i] = lol;
    }
    int tot = 0;
    for (int i = 0; i<num; i++){
        if(ans[i]==stud[i]){
            tot++;
        }
    }
    cout<<tot;
}