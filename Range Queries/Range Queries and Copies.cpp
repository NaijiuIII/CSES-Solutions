#include <bits/stdc++.h>
using namespace std;


struct node{
    long long sum;
    int left;
    int right;
};

int n,q;
vector<long long> a;
vector<node> tree;
vector<int> root;

int newnode(long long sum,int left,int right){
    tree.push_back({sum,left,right});
    return (int)tree.size()-1;
}

int build(int l,int r){
    if (l==r){
        return newnode(a[l],0,0);
    }
    int mid=(l+r)/2;

    int L=build(l,mid);
    int R=build(mid+1,r);

    return newnode(tree[L].sum+tree[R].sum,L,R);
}

int update(int old,int l,int r,int pos,long long x){
    if (l==r){
        return newnode(x,0,0);
    }
    int mid=(l+r)/2;

    int L=tree[old].left;
    int R=tree[old].right;

    if (pos<=mid){
        int newL=update(L,l,mid,pos,x);
        return newnode(tree[newL].sum+tree[R].sum,newL,R);
    }
    else{
        int newR=update(R,mid+1,r,pos,x);
        return newnode(tree[L].sum+tree[newR].sum,L,newR);
    }
}

long long query(int now,int l,int r,int ql,int qr){
    if (qr<l||r<ql) return 0;

    if (ql<=l&&r<=qr) return tree[now].sum;

    int mid=(l+r)/2;
    return query(tree[now].left,l,mid,ql,qr)
        +query(tree[now].right,mid+1,r,ql,qr);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;
    a.assign(n+1,0);

    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    tree.reserve(n*20+q*20);
    tree.push_back({0,0,0});
    root.push_back(0);
    root.push_back(build(1,n));

    while (q--){
        int op;
        cin>>op;

        if (op==1){
            int k,pos;
            long long x;
            cin>>k>>pos>>x;

            root[k]=update(root[k],1,n,pos,x);
        }
        else if (op==2){
            int k,l,r;
            cin>>k>>l>>r;
            cout<<query(root[k],1,n,l,r)<<'\n';
        }
        else{
            int k;
            cin>>k;

            root.push_back(root[k]);
        }
    }
    return 0;
}