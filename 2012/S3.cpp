//working (checked with DMOJ)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin>>N;
    int arr[1000];
    for (int i = 0; i<1000; i++){
        arr[i] = 0;
    }
    while (N>0){
        int r;
        cin>>r;
        arr[r-1]+=1;
        N--;
    }
    vector<int>max;
    int hold = 0;
    vector<int>min;
    int maximum = 0;
    int minimum = 0;
    for (int i = 0; i<1000; i++){
        if (arr[i]>maximum){
            max.clear();
            max.push_back(i);
            maximum = arr[i];
        }
        else if (arr[i]==maximum){
            max.push_back(i);
        }
    }
    if (max.size()>1){
        cout<<abs(max[0]-max[max.size()-1]);
    }
    else{
        for (int i = 0; i<1000; i++){
            if (arr[i]!=maximum&&arr[i]>minimum){
                minimum = arr[i];
                min.clear();
                min.push_back(i);
            }
            if (arr[i]==minimum){
                min.push_back(i);
            }
        }
        for (int i = 0; i<min.size(); i++){
            if (abs(min[i]-max[0])>hold){
                hold = abs(min[i]-max[0]);
            }
        }
        cout<<hold;
    }
}