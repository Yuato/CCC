#include <bits/stdc++.h>

using namespace std;

int main() {
    string str1;
    string str2;
    cin>>str1>>str2;
    int inx = 0;
    char silly;
    char chg;
    char quiet = '-';
    for (int i = 0; i<str1.size();i++){
        int holder = i;
        if (str2[inx]!=str1[i]){
            while (i<str1.size()&&str1[i+1]==str1[i]){
                i++;
            }
            if (i<str1.size()&&str1[i+1]==str2[inx]){
                quiet = str1[i];
            }
            else{
                silly = str1[i];
                chg = str2[inx];
                inx = inx+(i-holder);
            }
        }
        else{
            inx++;
        }
    }
}