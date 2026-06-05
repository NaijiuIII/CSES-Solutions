#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> x,p,ans;
vector<int> tree;

void build(int id,int l,int r){
    if (l==r){
        tree[id]=1;
        return;
    }

    int mid=(l+r)/2;

    build(id*2,l,mid);
    build(id*2+1,mid+1,r);

    tree[id]=tree[id*2]+tree[id*2+1];
}

int query(int id,int l,int r,int k){
    if (l==r){
        return l;
    }

    int mid=(l+r)/2;
    if (tree[id*2]>=k){
        return query(id*2,l,mid,k);
    }
    else{
        return query(id*2+1,mid+1,r,k-tree[id*2]);
    }
}

void update(int id,int l,int r,int pos){
    if (l==r){
        tree[id]=0;
        return;
    }

    int mid=(l+r)/2;

    if (pos<=mid) update(id*2,l,mid,pos);
    else update(id*2+1,mid+1,r,pos);

    tree[id]=tree[id*2]+tree[id*2+1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    x.assign(n+1,0);
    p.assign(n+1,0);
    tree.assign(4*n+1,0);

    for (int i=1;i<=n;i++){
        cin>>x[i];
    }
    
    build(1,1,n);

    for (int i=1;i<=n;i++){
        if (i!=1) cout<<' ';

        cin>>p[i];
        int pos=query(1,1,n,p[i]);
        cout<<x[pos];
        update(1,1,n,pos);
    }
    return 0;
}