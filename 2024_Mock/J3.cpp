#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string RGB;
    cin>>n>>RGB;
    long long total = 0, red0 = 0, red1=0;
    for (int i = 0; i<n; i++){
        char chr = RGB[i];
        if (chr == 'R'){
            red0++;
        }
        else if (chr=='G'){
            red1 = red0;
            red0 = 0;
        }
        else if (chr=='B'){
            total+=red1;
        }
    }
    cout<<total;
}