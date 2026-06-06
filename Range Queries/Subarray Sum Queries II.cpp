#include <bits/stdc++.h>
using namespace std;

struct node{
    long long sum,pre,suf,ans;
};

int n,q;
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

node query(int id,int l,int r,int ql,int qr){
    if (r<ql||l>qr) return {0,0,0,0};

    if (l>=ql&&r<=qr) return tree[id];

    int mid=(l+r)/2;

    node left=query(id*2,l,mid,ql,qr);
    node right=query(id*2+1,mid+1,r,ql,qr);

    return merge(left,right);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;
    a.assign(n+1,0);
    tree.assign(4*n+1,{0,0,0,0});

    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    build(1,1,n);

    while (q--){
        int a,b;
        cin>>a>>b;

        cout<<query(1,1,n,a,b).ans<<'\n';
    }
    return 0;
}