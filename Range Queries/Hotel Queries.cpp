#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<long long> room;
vector<long long> tree;

void build(int id,int l,int r){
    if (l==r){
        tree[id]=room[l];
        return;
    }
    int mid=(l+r)/2;

    build(id*2,l,mid);
    build(id*2+1,mid+1,r);

    tree[id]=max(tree[id*2],tree[id*2+1]);
}

int check(int id,int l,int r,long long x){
    if (tree[id]<x) return 0;

    if (l==r) return l;

    int mid=(l+r)/2;

    if (tree[id*2]>=x){
        return check(id*2,l,mid,x);
    }
    else{
        return check(id*2+1,mid+1,r,x);
    }
}

void update(int id,int l,int r,int pos,long long x){
    if (l==r){
        tree[id]=x;
        return;
    }

    int mid=(l+r)/2;
    if (pos<=mid){
        update(id*2,l,mid,pos,x);
    }
    else{
        update(id*2+1,mid+1,r,pos,x);
    }

    tree[id]=max(tree[id*2],tree[id*2+1]);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    room.assign(n+1,0);
    tree.assign(4*n+2,0);
    for (int i=1;i<=n;i++) cin>>room[i];

    build(1,1,n);
    
    long long x;
    for (int i=0;i<m;i++){
        if (i) cout<<' ';
        cin>>x;

        int pos=check(1,1,n,x);
        cout<<pos;
        if (pos!=0){
            room[pos]-=x;
            update(1,1,n,pos,room[pos]);
        }
    }
    return 0;
}