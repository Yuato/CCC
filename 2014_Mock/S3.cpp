#include <bits/stdc++.h>

using namespace std;

int main() {
    int R, C;
    cin>>R>>C;
    vector<vector<int>>sheet;
    vector<int>order;

    for (int i = 0; i<R; i++){
        sheet.push_back(order);
        for (int j = 0; j<C; j++){
            int a; cin>>a;
            sheet[i].push_back(a);
        }
        order.push_back(i);
    }
                                                                    
    
}