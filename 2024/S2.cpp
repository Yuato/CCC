#include <bits/stdc++.h>

using namespace std;


int main() {
    int N, L; 
    cin>>N>>L;
    int arr[40];
    
    while (N>0){
        string lol;
        cin>>lol;
        for (int i = 0 ;i<40; i++){
            arr[i] = 0;
        }
        for (int i = 0; i<L; i++){
            int inx = ((int)lol[i])-96;
            arr[inx]+=1;
        }
        bool poss = true;
        bool poss2 = true;
        for (int i = 0; i<L; i++){
            if (i%2==0&&arr[((int)lol[i])-96]>1){
                poss = false;
                break;
            }
            else if(i%2==1&&arr[((int)lol[i])-96]==1){
                poss = false;
                break;
            }
        }
        for (int i = 0; i<L; i++){
            if (i%2==0&&arr[((int)lol[i])-96]==1){
                poss2 = false;
                break;
            }
            else if(i%2==1&&arr[((int)lol[i])-96]>1){
                poss2 = false;
                break;
            }
        }
        if (poss2){
            cout<<"T";
        }
        else if (poss){
            cout<<"T";
        }
        else{
            cout<<"F";
        }
        if (N-1!=0){
            cout<<'\n';
        }
        N--;

    }
    return 0;
}