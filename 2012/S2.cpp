#include <bits/stdc++.h>

using namespace std;

int main() {
    map<char,int>roman;
    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;
    string str;
    cin>>str;
    int keep = roman.at(str[1]);
    int arkeep = (int)str[0]-48;
    int total = 0;
    for (int i = 2; i<str.size(); i+=2){
        int arab = (int)str[i]-48;
        char rmn = str[i+1];
        if (roman.at(rmn)>keep){
            total-=keep*arkeep;
            keep = roman.at(rmn);
            arkeep = arab;
        }
        else{
            total+=keep*arkeep;
            keep = roman.at(rmn);
            arkeep = arab;
        }
    }
    total+=keep*arkeep;
    cout<<total;
}