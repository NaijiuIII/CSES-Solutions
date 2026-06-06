#include <bits/stdc++.h>
using namespace std;

struct node{
    long long sum,pre,suf,ans;
};

int n,m;
vector<long long> a;
vector<node> tree;

node merge (node l,node r){
    node res;
    res.sum=l.sum+r.sum;

    res.pre=max(l.pre,l.sum+r.pre);
    res.suf=max(r.suf,r.sum+l.suf);
    res.ans=max({l.ans,r.ans,l.suf+r.pre});

    return res;
}

void build(int id,int l,int r){
    if (l==r){
        long long x=a[l];
        tree[id].sum=x;
        tree[id].pre=max(0LL,x);
        tree[id].suf=max(0LL,x);
        tree[id].ans=max(0LL,x);
        return;
    }

    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);

    tree[id]=merge(tree[id*2],tree[id*2+1]);
}

void update(int id,int l,int r,int pos,long long val){
    if (l==r){
        tree[id].sum=val;
        tree[id].pre=max(0LL,val);
        tree[id].suf=max(0LL,val);
        tree[id].ans=max(0LL,val);
        return;
    }

    int mid=(l+r)/2;

    if (pos<=mid) update(id*2,l,mid,pos,val);
    else update(id*2+1,mid+1,r,pos,val);

    tree[id]=merge(tree[id*2],tree[id*2+1]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    a.assign(n+1,0);
    tree.assign(4*n+1,{0,0,0,0});

    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    build(1,1,n);

    while (m--){
        int k;
        long long x;
        cin>>k>>x;

        update(1,1,n,k,x);
        cout<<tree[1].ans<<'\n';
    }
    return 0;
}