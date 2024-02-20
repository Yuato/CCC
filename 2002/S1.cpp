//CCC '02 S1 - The Students' Council Breakfast
//working (checked with DMOJ)

#include <bits/stdc++.h>

using namespace std;

int main(){
    int P,G,R,O, price, total = 0;
    cin>>P>>G>>R>>O>>price;
    int minimum = price;
    for (int o = price/O; o>=0 ;o--){
        for (int r = (price-o*O)/R; r>=0;r--){
            for (int g = (price-o*O-r*R)/G; g>=0;g--){
                if ((price-o*O-r*R-g*G)%P==0){
                    total++;
                    cout<<"# of PINK is "<<(price-o*O-r*R-g*G)/P<<" # of GREEN is "<<g<<" # of RED is "<<r<<" # of ORANGE is "<<o<<'\n';
                    if (minimum>(price-o*O-r*R-g*G)/P+g+r+o){
                        minimum = (price-o*O-r*R-g*G)/P+g+r+o;
                    }
                }
            }
        }
    }
    cout<<"Total combinations is "<< total<<"."<<'\n';
    cout<<"Minimum number of tickets to print is "<<minimum<<".";
}