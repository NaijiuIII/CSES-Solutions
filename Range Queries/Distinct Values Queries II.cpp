#include <bits/stdc++.h>
using namespace std;

int n,q;
vector<long long> a;
vector<int> nxt;
vector<long long> tree;
map<long long,set<int>> pos;

void build(int id,int l,int r){
    if (l==r){
        tree[id]=nxt[l];
        return;
    }

    int mid=(l+r)/2;

    build(id*2,l,mid);
    build(id*2+1,mid+1,r);

    tree[id]=min(tree[id*2],tree[id*2+1]);
}

void update(int id,int l,int r,int pos,int val){
    if (l==r){
        tree[id]=val;
        return;
    }
    int mid=(l+r)/2;

    if (pos<=mid) update(id*2,l,mid,pos,val);
    else update(id*2+1,mid+1,r,pos,val);

    tree[id]=min(tree[id*2],tree[id*2+1]);
}

long long query(int id,int l,int r,int ql,int qr){
    if (ql<=l&&qr>=r){
        return tree[id];
    }

    if (r<ql||l>qr) return 4e18;
    int mid=(l+r)/2;

    return min(query(id*2,l,mid,ql,qr),
            query(id*2+1,mid+1,r,ql,qr));
}

void fix(int k,long long u){
    long long old=a[k];

    auto &s1=pos[old];
    auto it1=s1.find(k);

    int pre1=-1;
    int ne1=n+1;

    if (it1!=s1.begin()) pre1=*prev(it1);
    if (next(it1)!=s1.end()) ne1=*next(it1);

    if (pre1!=-1){
        nxt[pre1]=ne1;
        update(1,1,n,pre1,nxt[pre1]);
    }
    s1.erase(it1);


    auto &s2=pos[u];
    auto it2=s2.lower_bound(k);

    int pre2=-1;
    int ne2=n+1;

    if (it2!=s2.begin()) pre2=*prev(it2);
    if (it2!=s2.end()) ne2=*it2;

    if (pre2!=-1){
        nxt[pre2]=k;
        update(1,1,n,pre2,nxt[pre2]);
    }

    nxt[k]=ne2;
    update(1,1,n,k,nxt[k]);

    s2.insert(k);
    a[k]=u;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;
    a.assign(n+1,0);
    nxt.assign(n+1,n+1);
    tree.assign(4*n+1,0);


    for (int i=1;i<=n;i++){
        cin>>a[i];

        pos[a[i]].insert(i);
    }

    for (auto &[val,s]:pos){
        int pre=-1;
        for (int x:s){
            if (pre!=-1){
                nxt[pre]=x;
            }
            pre=x;
        }
    }

    build(1,1,n);

    for (int i=0;i<q;i++){
        int op;
        cin>>op;

        if (op==1){
            int k;
            long long u;
            cin>>k>>u;

            fix(k,u);
        }
        else{
            int l,r;
            cin>>l>>r;

            long long k=query(1,1,n,l,r);

            if (k<=r) cout<<"NO\n";
            else cout<<"YES\n";
        }
    }
    return 0;
}