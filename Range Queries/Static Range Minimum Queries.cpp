#include <bits/stdc++.h>
using namespace std;

int n,q;
vector<long long> a;
vector<long long> tree;

void build(int id,int l,int r){
    if (l==r){
        tree[id]=a[l];
        return;
    }

    int mid=(l+r)/2;

    build(id*2,l,mid);
    build(id*2+1,mid+1,r);

    tree[id]=min(tree[id*2],tree[id*2+1]);
}

long long query(int id,int l,int r,int ql,int qr){
    if (ql<=l&&r<=qr){
        return tree[id];
    }

    if (l>qr||r<ql){
        return 4e18;
    }

    int mid=(l+r)/2;

    auto lans=query(id*2,l,mid,ql,qr);
    auto rans=query(id*2+1,mid+1,r,ql,qr);

    return min(lans,rans);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;
    a.assign(n+1,0);
    tree.assign(4*n+1,4e18);

    for (int i=1;i<=n;i++) cin>>a[i];

    build(1,1,n);

    while (q--){
        int l,r;
        cin>>l>>r;

        cout<<query(1,1,n,l,r)<<'\n';
    }
    return 0;
}