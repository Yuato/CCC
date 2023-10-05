#include <bits/stdc++.h>

using namespace std;

int main()
{
    int count = 0;
    int num_columns,x;
    cin>>num_columns;

    int row1 [num_columns+2];
    row1[0]=0;
    row1[num_columns+1]= 0;
    int row2 [num_columns+2];
    row2[0]=0;
    row2[num_columns+1]= 0;

    for (int i = 0; i<num_columns;i++){
        cin>>x;
        row1[i+1] = x;
    }
    for (int i = 0; i<num_columns;i++){
        cin>>x;
        row2[i+1] = x;
    }

    for (int i = 0; i<num_columns;i++){
        if (row1[i+1] == 1){
            if (row1[i]==0){
                count++;
            }
            if (row1[i+2]==0){
                count++;
            }
        }
        if (row2[i+1] == 1){
            if (row2[i]==0){
                count++;
            }
            if (row2[i+2] ==0){
                count++;
            }
        }
        if((i+1)%2==1){
            if (row1[i+1]!=row2[i+1]){
                count++;
            }
        }
        else{
            if (row1[i+1] == 1){
                count++;
            }
            if (row2[i+1]==1){
                count++;
            }
        }
    }
    cout<<count;
}
