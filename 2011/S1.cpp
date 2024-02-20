#include <bits/stdc++.h>

using namespace std;

int main() {
    string sen;
    int n;
    cin>>n;
    int eng = 0, fren = 0;
    while (n>=0){
        getline(cin, sen);
        for (int i = 0; i<sen.size(); i++){
            if (sen[i]=='S'||sen[i]=='s'){
                fren++;
            }
            else if (sen[i]=='T'||sen[i]=='t'){
                eng++;
            }
        }
        n--;
    }
    if (fren>=eng){
        cout<<"French";
    }
    else{
        cout<<"English";
    }
}