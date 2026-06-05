#include <bits/stdc++.h>
using namespace std;

int n,q;
vector<long long> p;
vector<long long> treel,treer;

void build(int id,int l,int r){
    if (l==r){
        treel[id]=p[l]-l;
        treer[id]=p[l]+l;
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);

    treel[id]=min(treel[id*2],treel[id*2+1]);
    treer[id]=min(treer[id*2],treer[id*2+1]);
}

void update(int id,int l,int r,int pos,long long val){
    if (l==r){
        treel[id]=val-l;
        treer[id]=val+l;
        return;
    }

    int mid=(l+r)/2;

    if (pos<=mid) update(id*2,l,mid,pos,val);
    else update(id*2+1,mid+1,r,pos,val);

    treel[id]=min(treel[id*2],treel[id*2+1]);
    treer[id]=min(treer[id*2],treer[id*2+1]);
}

long long queryl(int id,int l,int r,int ql,int qr){
    if (qr<l||ql>r) return 4e18;
    if (ql<=l&&r<=qr) return treel[id];

    int mid=(l+r)/2;
    long long lans=queryl(id*2,l,mid,ql,qr);
    long long rans=queryl(id*2+1,mid+1,r,ql,qr);

    return min(lans,rans);
}

long long queryr(int id,int l,int r,int ql,int qr){
    if (qr<l||ql>r) return 4e18;
    if (ql<=l&&r<=qr) return treer[id];

    int mid=(l+r)/2;
    long long lans=queryr(id*2,l,mid,ql,qr);
    long long rans=queryr(id*2+1,mid+1,r,ql,qr);

    return min(lans,rans);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;
    p.assign(n+1,0);
    treel.assign(4*n+1,0);
    treer.assign(4*n+1,0);

    for (int i=1;i<=n;i++) cin>>p[i];

    build(1,1,n);

    while (q--){
        int op;
        cin>>op;

        if (op==1){
            int k;
            long long x;
            cin>>k>>x;
            p[k]=x;
            update(1,1,n,k,x);
        }
        else{
            int k;
            cin>>k;
            long long ans=4e18;
            if (k>1){
                ans=min(ans,queryl(1,1,n,1,k)+k);
            }
            if (k<n){
                ans=min(ans,queryr(1,1,n,k,n)-k);
            }

            ans=min(ans,p[k]);
            cout<<ans<<'\n';
        }
    }
    return 0;
}