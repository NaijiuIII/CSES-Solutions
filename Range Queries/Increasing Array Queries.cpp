#include <bits/stdc++.h>
using namespace std;

struct node{
    long long sum=0;
    vector<long long> mxs;
    vector<long long> pre;
};

int n,q;
vector<node> tree;
vector<long long> a;

void pull(int id){
    tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;

    tree[id].mxs.clear();
    tree[id].pre.clear();

    for (long long x:tree[id*2].mxs){
        tree[id].mxs.push_back(x);
    }

    long long cur=tree[id].mxs.back();

    for (long long x:tree[id*2+1].mxs){
        tree[id].mxs.push_back(max(cur,x));
    }

    tree[id].pre.push_back(0);

    for (long long x:tree[id].mxs){
        tree[id].pre.push_back(tree[id].pre.back()+x);
    }
}

void build(int id,int l,int r){
    if (l==r){
        tree[id].sum=a[l];
        tree[id].mxs.push_back(a[l]);
        tree[id].pre.push_back(0);
        tree[id].pre.push_back(a[l]);
        return;
    }

    int mid=(l+r)/2;

    build(id*2,l,mid);
    build(id*2+1,mid+1,r);

    pull(id);
}

void getnode(int id,int l,int r,int ql,int qr,auto &nodes){
    if (ql<=l&&r<=qr){
        nodes.push_back(id);
        return;
    }

    if (r<ql || l>qr) return;

    int mid=(l+r)/2;

    getnode(id*2,l,mid,ql,qr,nodes);
    getnode(id*2+1,mid+1,r,ql,qr,nodes);
}

long long calc(int id,long long &cur){
    auto &v=tree[id].mxs;
    auto &pre=tree[id].pre;

    int len=v.size();

    int p=upper_bound(v.begin(),v.end(),cur)-v.begin();

    long long need=cur*p+pre[len]-pre[p];
    cur=max(cur,v.back());
    return need-tree[id].sum;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;
    a.assign(n+1,0);
    tree.resize(4*n+1);

    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    build(1,1,n);

    while (q--){
        int l,r;
        cin>>l>>r;

        vector<int> nodes;
        getnode(1,1,n,l,r,nodes);

        long long cur=0;
        long long ans=0;

        for (int id:nodes){
            ans+=calc(id,cur);
        }

        cout<<ans<<'\n';
    }
    return 0;
}