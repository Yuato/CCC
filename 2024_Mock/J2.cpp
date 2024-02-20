#include <bits/stdc++.h>

using namespace std;

int main() {
    double a,b;
    int n,k;
    cin>>n>>a>>b>>k;
    string streak;
    cin>>streak;
    for (int i = 0; i<streak.size(); i++){
        char result = streak[i];
        double score;
        if (result == 'T'){
            score = 0.5;
        }
        else if (result == 'W'){
            score = 1;
        }
        else{
            score = 0;
        }
        double expect = 1/(pow(10,(b-a)/400)+1);
        double change = (score-expect)*k;
        a = a+change;
        b = b-change;
        cout<<fixed<<setprecision(1)<<a<<" "<<b;
        if (i+1!=streak.size()){
            cout<<'\n';
        } 
    }
}