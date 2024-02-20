#include <iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    int arr[50000];
    arr[0]= 1;
    arr[1] = 1;
    for (int k = 2; k <50000; k++){
        arr[k]=arr[k-1]+arr[k-2];
    }
    while (n>0){
        int a;
        cin>>a;
        bool div = false;
        for (int i = 2; i<a; i++){
            if (a%i==0){
                div = true;
                break;
            }
        }
        for (int i = 0; i < 50000; i++){
            
            if (a == arr[i]){
                if (div){
                    cout<<"YES";
                }
                else{
                    cout<<"NO";
                }
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