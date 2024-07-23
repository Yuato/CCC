#include <bits/stdc++.h>

using namespace std;

int arr[100000];
int tree[400000];

void pushup(int v){
    tree[v] = tree[v*2]+tree[v*2+1];
}

void build(int v, int l, int r){
    if (l==r){
        tree[v] = arr[l];
        return;
    }
    int m = (l+r)/2;
    build (v*2, l, m);
    build(v*2+1, m+1, r);
}

int query(int v, int l, int r, int ql, int qr){
    if (ql<=l&&qr>=r){
        return tree[v];
    }
    else if (ql>r||qr<l){
        return 0;
    }
    int m = (l+r)/2;
    return query(v*2,l,m,ql,qr)+query(v*2+1,m+1,r,ql,qr);
}

void update(int v, int l, int r, int pos){
    if (l==r){
        tree[v]+=1;
        return;
    }
    int m = (l+r)/2;
    if (pos<=m){
        update(v*2, l, m, pos);
    }
    else{
        update(v*2+1,m+1,r,pos);
    }
    pushup(v);
}

int main() {
    map<long long,int>mp;
    vector<long long>list;
    vector<long long>slist;
    int T;
    cin>>T;
    for (int i = 1; i<T+1; i++){
        arr[i] = 0;
        int a; cin>>a;
        list.push_back(a);
        slist.push_back(a);
    }
    sort(slist.begin(), slist.end());
    long long cur = -1;
    int sz = 1;
    for (int i = 0; i<T; i++){
        if (slist[i]!=cur){
            mp[slist[i]] = sz;
            sz++;
        }
        cur = slist[i];
    }
    build(1,1,sz-1);
    long long tot = 0;
    for (int i = 0; i<list.size(); i++){
        int node = mp[list[i]];
        int rank = query(1,1,sz-1,1,node);
        update(1,1,sz-1,node);
        tot += 1+(i-rank);
    }
    cout<<fixed<<setprecision(2)<<(double)tot/list.size();
}