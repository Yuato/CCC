#include <iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    int arr[100000];
    arr[0]= 1;
    arr[1] = 1;
    for (int k = 2; k <100000; k++){
        arr[k]=arr[k-1]+arr[k-2];
    }
    while (n>0){
        int a;
        cin>>a;
        for (int i = 0; i < 100000; i++){
            if (a == arr[i]){
                cout<<"YES";
                break;
            }
            else if (arr[i]>a){
                cout<<"NO";
                break;
            }
        }
        if (n-1!=0){
            cout<<'\n';
        }
        n--;
    }
}