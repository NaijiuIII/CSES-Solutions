#include <bits/stdc++.h>
using namespace std;

const int N=200005;
const int M=400005;

int n,q;

int head[N],to[M],nxt[M],idx=0;
int val[N];

int fa[N];
int dep[N];
int sz[N];
int son[N];

int top[N];
int pos[N];
int id[N];
int seg[N*4];

int tot=0;

void add(int a,int b){
    idx++;
    to[idx]=b;
    nxt[idx]=head[a];
    head[a]=idx;
}

void dfs1(int u,int p){
    fa[u]=p;
    dep[u]=dep[p]+1;
    sz[u]=1;
    son[u]=0;

    for (int i=head[u];i;i=nxt[i]){
        int v=to[i];

        if (v==p) continue;

        dfs1(v,u);
        sz[u]+=sz[v];

        if (son[u]==0||sz[v]>sz[son[u]]){
            son[u]=v;
        }
    }
}

void dfs2(int u,int tp){
    top[u]=tp;
    pos[u]=++tot;
    id[tot]=u;

    if (son[u]){
        dfs2(son[u],tp);
    }

    for (int i=head[u];i;i=nxt[i]){
        int v=to[i];

        if (v==fa[u]||v==son[u]) continue;

        dfs2(v,v);
    }
}

void build(int o,int l,int r){
    if (l==r){
        seg[o]=val[id[l]];
        return;
    }

    int mid=(l+r)/2;
    build(o*2,l,mid);
    build(o*2+1,mid+1,r);

    seg[o]=max(seg[o*2],seg[o*2+1]);
}

void update(int o,int l,int r,int p,int x){
    if (l==r){
        seg[o]=x;
        return;
    }

    int mid=(l+r)/2;

    if (p<=mid){
        update(o*2,l,mid,p,x);
    }
    else update(o*2+1,mid+1,r,p,x);

    seg[o]=max(seg[o*2],seg[o*2+1]);
}

int query(int o,int l,int r,int ql,int qr){
    if (ql<=l&&r<=qr){
        return seg[o];
    }

    int mid=(l+r)/2;
    int ans=0;

    if (ql<=mid) ans=max(ans,query(o*2,l,mid,ql,qr));
    if (qr>mid) ans=max(ans,query(o*2+1,mid+1,r,ql,qr));

    return ans;
}

int query_path(int a,int b){
    int ans=0;

    while(top[a]!=top[b]){
        if (dep[top[a]]<dep[top[b]]) swap(a,b);

        ans=max(ans,query(1,1,n,pos[top[a]],pos[a]));
        a=fa[top[a]];
    }

    if (dep[a]>dep[b]){
        swap(a,b);
    }

    ans=max(ans,query(1,1,n,pos[a],pos[b]));
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;

    for (int i=1;i<=n;i++){
        cin>>val[i];
    }

    for (int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;

        add(a,b);
        add(b,a);
    }

    dfs1(1,0);
    dfs2(1,1);
    build(1,1,n);

    while (q--){
        int op;
        cin>>op;

        if (op==1){
            int s,x;
            cin>>s>>x;

            update(1,1,n,pos[s],x);
        }
        else{
            int a,b;
            cin>>a>>b;
            cout<<query_path(a,b)<<' ';
        }
    }

    return 0;
}