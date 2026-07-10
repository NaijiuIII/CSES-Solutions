#include <bits/stdc++.h>
using namespace std;

int n,k1,k2;
vector<vector<int>> g;
vector<int> sz;
vector<int> vis;
vector<int> cnt;
vector<int> pre;

long long ans=0;

void dfs(int u,int fa){
    sz[u]=1;

    for (int v:g[u]){
        if (v==fa||vis[v]) continue;

        dfs(v,u);
        sz[u]+=sz[v];
    }
}

int centroid(int u,int fa,int tot){
    for (int v:g[u]){
        if (v==fa||vis[v]) continue;
        
        if (sz[v]*2>tot) return centroid(v,u,tot);
    }

    return u;
}

void getdepth(int u,int fa,int d,vector<int>&dep){
    if (d>k2) return;

    dep.push_back(d);

    for (int v:g[u]){
        if (v==fa||vis[v]) continue;
        getdepth(v,u,d+1,dep);
    }
}

long long leq(const vector<int> &dep,int K){
    if (K<0) return 0;

    int mx=0;

    for (int d:dep){
        if (d>K) continue;

        cnt[d]++;

        mx=max(mx,d);
    }

    pre[0]=cnt[0];
    for (int i=1;i<=mx;i++){
        pre[i]=pre[i-1]+cnt[i];
    }
    
    long long order=0;

    for (int d=0;d<=mx;d++){
        if (cnt[d]==0) continue;

        int r=min(mx,K-d);

        if (r>=0){
            order+=1LL*cnt[d]*pre[r];
        }
    }

    long long own=0;
    for (int d=0;d<=mx&&2*d<=K;d++) own+=cnt[d];
    for (int d=0;d<=mx;d++) cnt[d]=0;

    return (order-own)/2;
}

long long calc(const vector<int>&dep){
    return leq(dep,k2)-leq(dep,k1-1);
}

void solve(int u){
    dfs(u,0);

    int tot=sz[u];

    int rt=centroid(u,0,tot);
    vis[rt]=1;

    vector<int> all;
    all.reserve(tot);
    all.push_back(0);

    vector<int> dep;

    for (int v:g[rt]){
        if (vis[v]) continue;
        dep.clear();

        getdepth(v,rt,1,dep);

        ans-=calc(dep);
        for (int d:dep){
            all.push_back(d);
        }
    }

    ans+=calc(all);

    for (int v:g[rt]){
        if (vis[v]) continue;

        solve(v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k1>>k2;

    g.resize(n+1);
    sz.assign(n+1,0);
    vis.assign(n+1,0);
    cnt.assign(k2+1,0);
    pre.assign(k2+1,0);

    for (int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    solve(1);

    cout<<ans<<'\n';
    return 0;
}