#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<vector<int>> g;
vector<int> sz;
vector<int> vis;
vector<int> cnt;
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

        if (sz[v]*2>tot){
            return centroid(v,u,tot);
        }
    }

    return u;
}

void getdepth(int u,int fa,int d,vector<int>& dep){
    if (d>k) return;

    dep.push_back(d);

    for (int v:g[u]){
        if (v==fa||vis[v]) continue;
        
        getdepth(v,u,d+1,dep);
    }
}

void solve(int u){
    dfs(u,0);

    int rt=centroid(u,0,sz[u]);

    vis[rt]=1;
    vector<int> used;

    cnt[0]=1;
    used.push_back(0);

    for (int v:g[rt]){
        if (vis[v]) continue;

        vector<int> dep;
        getdepth(v,rt,1,dep);

        for (int d:dep){
            if (d<=k){
                ans+=cnt[k-d];
            }
        }
        for (int d:dep){
            if (d<=k){
                cnt[d]++;
                used.push_back(d);
            }
        }
    }
    for (int d:used){
        cnt[d]=0;
    }

    for (int v:g[rt]){
        if (vis[v]) continue;

        solve(v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;
    g.resize(n+1);
    sz.assign(n+1,0);
    vis.assign(n+1,0);
    cnt.assign(k+1,0);

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