#include <bits/stdc++.h>
using namespace std;

int n,q;
vector<long long> tree;
vector<long long> a;

vector<long long> lazyadd,lazyset;
vector<int> hashset;

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

void applyadd(int id,int l,int r,long long x){
    tree[id]+=(r-l+1)*x;
    if (hashset[id]){
        lazyset[id]+=x;
    }
    else{
        lazyadd[id]+=x;
    }
}

void applyset(int id,int l,int r,long long x){
    tree[id]=(r-l+1)*x;

    hashset[id]=1;
    lazyset[id]=x;

    lazyadd[id]=0;
}

void push(int id,int l,int r){
    if (l==r) return;
    int mid=(l+r)/2;

    if (hashset[id]){
        applyset(id*2,l,mid,lazyset[id]);
        applyset(id*2+1,mid+1,r,lazyset[id]);

        lazyset[id]=0;
        hashset[id]=0;
    }

    if (lazyadd[id]!=0){
        applyadd(id*2,l,mid,lazyadd[id]);
        applyadd(id*2+1,mid+1,r,lazyadd[id]);

        lazyadd[id]=0;
    }
}

void add(int id,int l,int r,int pl,int pr,long long x){
    if (l>pr||r<pl) return;

    if (l>=pl&&r<=pr){
        applyadd(id,l,r,x);
        return;
    }

    push(id,l,r);
    int mid=(l+r)/2;

    add(id*2,l,mid,pl,pr,x);
    add(id*2+1,mid+1,r,pl,pr,x);
    tree[id]=tree[id*2]+tree[id*2+1];
}

void setval(int id,int l,int r,int pl,int pr,long long x){
    if (l>pr||r<pl) return;

    if (l>=pl && r<=pr){
        applyset(id,l,r,x);
        return;
    }

    push(id,l,r);

    int mid=(l+r)/2;

    setval(id*2,l,mid,pl,pr,x);
    setval(id*2+1,mid+1,r,pl,pr,x);

    tree[id]=tree[id*2]+tree[id*2+1];
}

long long query(int id,int l,int r,int pl,int pr){
    if (l>pr||r<pl) return 0;
    if (l>=pl&&r<=pr) return tree[id];

    push(id,l,r);

    int mid=(l+r)/2;

    return query(id*2,l,mid,pl,pr)+
        query(id*2+1,mid+1,r,pl,pr);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;
    tree.assign(4*n+1,0);
    a.assign(n+1,0);

    lazyadd.assign(4*n+1,0);
    lazyset.assign(4*n+1,0);
    hashset.assign(4*n+1,0);

    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    build(1,1,n);

    while (q--){
        int op;
        cin>>op;

        if (op==1){
            int l,r;
            long long x;
            cin>>l>>r>>x;

            add(1,1,n,l,r,x);
        }
        else if (op==2){
            int l,r;
            long long x;
            cin>>l>>r>>x;

            setval(1,1,n,l,r,x);
        }
        else{
            int l,r;
            cin>>l>>r;

            cout<<query(1,1,n,l,r)<<'\n';
        }
    }
    return 0;
}