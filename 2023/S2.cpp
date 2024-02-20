#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, h;
    vector<int>mountains;
    cin>>N;
    int arr[N];
    for (int i = 0; i<N; i++){
        cin>>h;
        mountains.push_back(h);
        arr[i]=INT32_MAX;
    }
    for (int i = 0; i<N*2+1; i++){
        int min=0;
        int index = 0;
        if (i%2==1){
            while(((i/2)-index>=0)&&((i/2)+index<=N-1)){
                min += abs(mountains[i/2-index]-mountains[i/2+index]);
                if (min<arr[index*2]){
                    arr[index*2]=min;
                }
                index++;
            }
        }
        else{
            while((i/2-index-1>=0)&&(i/2+index<=N-1)){
                min+=abs(mountains[(i/2)-index-1]-mountains[(i/2)+index]);
                if (min<arr[index*2+1]){
                    arr[index*2+1]=min;
                }
                index++;
            }
        }
    }   
for (int i = 0; i<N; i++){
        cout<<arr[i];
        if (i+1!=N){
            cout<<" ";
        }
    }
}
