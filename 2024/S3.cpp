#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    vector<int>swipe;
    vector<int>counter;
    deque<int>indexl;
    deque<int>indexr;
    deque<char>move;
    int make[n];
    int copy[n];
    for (int i = 0; i<n; i++){
        int a; cin>>a;
        arr[i] = a;
    }
    int last;
    int count = 1;
    for (int i = 0; i<n; i++){
        int a; cin>>a;
        copy[i]==a;
        if (i==0){
            last = a;
        }
        else if (last==a){
            count++;
        }
        else{
            swipe.push_back(last);
            counter.push_back(count);
            count = 1;
            last = a;
        }
    }
    swipe.push_back(last);
    counter.push_back(count);
    count = 0;
    int c2 = -1;
    bool poss = true;
    int inx = 0;
    for (int i = 0; i<n; i++){
        if (arr[i]==swipe[inx]){
            if (c2<i-1){
                count++;
                move.push_back('L');
                indexl.push_back(c2+1);
                indexr.push_back(i);
            }
            c2+=counter[inx];
            if (c2>i){
                count++;
                move.push_front('R');
                indexl.push_front(i);
                indexr.push_front(c2);
            }
            inx++;
        }
        if (inx==swipe.size()){
            break;
        }
    }
    if (inx!=swipe.size()){
        poss = false;
    }
    if (poss){
        cout<<"YES"<<'\n'<<count;
        for (int i = 0; i<move.size(); i++){
            cout<<'\n';
            cout<<move[i]<<" "<<indexl[i]<<" "<<indexr[i];
        }
    }
    else{
        cout<<"NO";
    }
}