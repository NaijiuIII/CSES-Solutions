#include <bits/stdc++.h>
using namespace std;


struct node{
    int lson=0;
    int rson=0;
    long long sum=0;
};

int n,q;
vector<node> tree;
vector<int> root;
vector<pair<long long,int>> coin;
vector<long long> val;

int update(int pre,int l,int r,int pos,long long x){
    tree.push_back(tree[pre]);

    int now=tree.size()-1;
    tree[now].sum+=x;

    if (l==r){
        return now;
    }

    int mid=(l+r)/2;
    if (pos<=mid){
        tree[now].lson=update(tree[pre].lson,l,mid,pos,x);
    }
    else{
        tree[now].rson=update(tree[pre].rson,mid+1,r,pos,x);
    }
    return now;
}

long long query(int rt,int l,int r,int ql,int qr){
    if (rt==0){
        return 0;
    }

    if (ql<=l&&r<=qr){
        return tree[rt].sum;
    }

    int mid=(l+r)/2;
    long long res=0;
    if (ql<=mid) res+=query(tree[rt].lson,l,mid,ql,qr);
    if (qr>mid) res+=query(tree[rt].rson,mid+1,r,ql,qr);

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;
    coin.resize(n+1);
    val.resize(n+1);
    root.resize(n+1);
    tree.push_back({0,0,0});

    tree.reserve(n*20+1);

    for (int i=1;i<=n;i++){
        long long x;
        cin>>x;
        coin[i]={x,i};
    }

    sort(coin.begin(),coin.end());

    for (int i=1;i<=n;i++){
        val[i]=coin[i].first;
    }

    root[0]=0;
    for (int i=1;i<=n;i++){
        long long x=coin[i].first;
        int pos=coin[i].second;

        root[i]=update(root[i-1],1,n,pos,x);
    }

    while (q--){
        int l,r;
        cin>>l>>r;

        long long ans=1;

        while (1){
            int id=upper_bound(val.begin()+1,val.end(),ans)-val.begin()-1;
            long long s=query(root[id],1,n,l,r);

            if (s<ans){
                break;
            }
            ans=s+1;
        }

        cout<<ans<<'\n';
    }
    return 0;
}