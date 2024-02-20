//working (checked with DMOJ)
#include <bits/stdc++.h>

using namespace std;
// 4
// +++===!!!!
// 777777......TTTTTTTTTTTT
// (AABBC)
// 3.1415555
int main() {
    int n;
    string line;
    cin>>n;
    int count;
    bool l = false;
    while (n>=0){
        getline(cin, line);
        count = 1;
        for (int i = 0; i<line.size();i++){
            char current = line[i];
            if (i+1<line.size()&&current == line[i+1]){
                count++;
            }
            else{
                cout<<count<<' '<<current;
                count = 1;
                if (i+1!=line.size()){
                    cout<<' ';
                }
            }
        }
        n--;
        if (n>=0){
            cout<<'\n';
        }
    }
}