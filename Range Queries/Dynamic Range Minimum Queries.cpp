#include <bits/stdc++.h>
using namespace std;

int n,q;
vector<long long> tree;
vector<long long> a;

void build(int id,int l,int r){
    if (l==r){
        tree[id]=a[l];
        return;
    }

    int mid=(l+r)/2;

    build(2*id,l,mid);
    build(2*id+1,mid+1,r);

    tree[id]=min(tree[id*2],tree[id*2+1]);
}

void update(int id,int l,int r,int pos,long long val){
    if (l==r){
        tree[id]=val;
        return;
    }

    int mid=(l+r)/2;

    if (pos<=mid){
        update(id*2,l,mid,pos,val);
    }
    else{
        update(id*2+1,mid+1,r,pos,val);
    }

    tree[id]=min(tree[id*2],tree[id*2+1]);
}

long long query(int id,int l,int r,int ql,int qr){
    if (ql<=l && qr>=r){
        return tree[id];
    }

    if (r<ql||l>qr){
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

    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);

    while (q--){
        int op;
        cin>>op;

        if (op==1){
            int k;
            long long u;
            cin>>k>>u;
            update(1,1,n,k,u);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<'\n';
        }
    }
    return 0;
}