#include <bits/stdc++.h>
using namespace std;

int n,q;
vector<long long> tree,lazyk,lazyb,a;

long long getsum(long long l,long long r){
    return (l+r)*(r-l+1)/2;
}

void apply(int id,int l,int r,long long k,long long b){
    tree[id]+=k*getsum(l,r)+b*(r-l+1);
    lazyk[id]+=k;
    lazyb[id]+=b;
}

void push(int id,int l,int r){
    if (lazyk[id]==0&&lazyb[id]==0) return;

    int mid=(l+r)/2;
    apply(id*2,l,mid,lazyk[id],lazyb[id]);
    apply(id*2+1,mid+1,r,lazyk[id],lazyb[id]);

    lazyk[id]=0;
    lazyb[id]=0;
}

void build(int id,int l,int r){
    if (l==r){
        tree[id]=a[l];
        return;
    }

    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);

    tree[id]=tree[id*2]+tree[id*2+1];
}

void update(int id,int l,int r,int ql,int qr,long long k,long long b){
    if (qr<l||ql>r) return;

    if (ql<=l&&r<=qr){
        apply(id,l,r,k,b);
        return;
    }

    push(id,l,r);
    int mid=(l+r)/2;
    update(id*2,l,mid,ql,qr,k,b);
    update(id*2+1,mid+1,r,ql,qr,k,b);

    tree[id]=tree[id*2]+tree[id*2+1];
}

long long query(int id,int l,int r,int ql,int qr){
    if (qr<l||r<ql) return 0;

    if (ql<=l&&r<=qr){
        return tree[id];
    }

    push(id,l,r);
    int mid=(l+r)/2;
    return query(id*2,l,mid,ql,qr)
        +query(id*2+1,mid+1,r,ql,qr);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;
    a.assign(n+1,0);
    tree.assign(4*n+1,0);
    lazyk.assign(4*n+1,0);
    lazyb.assign(4*n+1,0);

    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);

    while (q--){
        int op;
        cin>>op;
        int a,b;
        cin>>a>>b;

        if (op==1){
            update(1,1,n,a,b,1,1-a);
        }
        else{
            cout<<query(1,1,n,a,b)<<'\n';
        }
    }
    return 0;
}