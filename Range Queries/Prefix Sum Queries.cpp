#include <bits/stdc++.h>
using namespace std;

int n,q;
vector<long long> sum,pre;
vector<long long> a;

void build(int id,int l,int r){
    if (l==r){
        sum[id]=a[l];
        pre[id]=max(a[l],pre[id]);

        return;
    }

    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);

    sum[id]=sum[id*2]+sum[id*2+1];
    pre[id]=max({pre[id],sum[id*2]+pre[id*2+1],pre[id*2]});
}

void update(int id,int l,int r,int pos,long long val){
    if (l==r){
        sum[id]=val;
        pre[id]=max(0*1LL,val);
        return;
    }

    int mid=(l+r)/2;
    if (pos<=mid){
        update(id*2,l,mid,pos,val);
    }
    else update(id*2+1,mid+1,r,pos,val);

    sum[id]=sum[id*2]+sum[id*2+1];
    pre[id]=max({0*1LL,sum[id*2]+pre[id*2+1],pre[id*2]});
}

pair<long long,long long> query(int id,int l,int r,int ql,int qr){
    if (qr<l||r<ql) return {0,0};
    if (ql<=l&&qr>=r) return {sum[id],pre[id]};

    int mid=(l+r)/2;
    auto lans=query(id*2,l,mid,ql,qr);
    auto rans=query(id*2+1,mid+1,r,ql,qr);

    long long s=lans.first+rans.first;
    long long p=max(lans.second,lans.first+rans.second);

    return {s,p};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;
    a.assign(n+1,0);
    sum.assign(4*n+1,0);
    pre.assign(4*n+1,0);

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
            int a,b;
            cin>>a>>b;
            cout<<query(1,1,n,a,b).second<<'\n';
        }
    }
    return 0;
}