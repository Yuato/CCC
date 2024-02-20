//working (checked with DMOJ)
#include <bits/stdc++.h>

using namespace std;

int main() {
    bool circ = false;
    int n;
    cin>>n;
    int arr[10000];
    while (n>0){
        int first, sec;
        cin>>first>>sec;
        arr[first] = sec;
        n--;
    }
    bool f = false;
    while (true) {
        int first, sec, placement, count =0;
        cin>>first>>sec;
        placement = arr[first];
        if (first==0&&sec==0){
            break;
        }
        else{
            if (f){
                cout<<'\n';
            }
            f=true;
            while (true){
                if (placement==sec){
                    circ = true;
                    break;
                }
                else if (placement == first){
                    circ = false;
                    break;
                }
                placement = arr[placement];
                count++;
            }
        }
        if (circ){
            cout<<"Yes "<<count;
        }
        else{
            cout<<"No";
        }
    }
}