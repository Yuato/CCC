#include <bits/stdc++.h>
#define pll pair<long long, long long>

using namespace std;

int main(){
    long long n,p,w,d;
    cin>>n;
    priority_queue <pll, vector<pll>, greater<pll>> pq;
    long long left=0, right=0, lw=0, rw = 0, min = INT64_MAX, curr = 0, mpos=0;
    for (int i = 0; i<n; i++){
        cin>>p>>w>>d;
        pq.push(pair(p+d,w)); 
        if (p-d>=0){
            left+=w*(p-d);
            lw+=w;
            pq.push(pair(p-d,-w));
        }
    }
    while (!pq.empty()){
        pll node = pq.top();
        long long pos = node.first;
        left = left-(pos-curr)*lw;
        right = right+(pos-curr)*rw;
        while (pos==pq.top().first&&!pq.empty()){
            long long chg = pq.top().second;
            if (chg<0){
                lw+=chg;
            }
            else{
                rw+=chg;
            }
            pq.pop();
        }
        curr = pos;
        if (left+right<min){
            mpos=pos;
            min = left+right;
        }
    }
    cout<<min;
}