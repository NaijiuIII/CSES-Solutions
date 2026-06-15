#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> sz;
vector<long long> ans;
vector<long long> depth;

void dfs1(int u,int fa){
    sz[u]=1;

    ans[1]+=depth[u];

    for (int v:g[u]){
        if (v==fa) continue;
        depth[v]=depth[u]+1;
        dfs1(v,u);

        sz[u]+=sz[v];
    }
}

void dfs2(int u,int fa){
    for (int v:g[u]){
        if (v==fa) continue;

        ans[v]=ans[u]-sz[v]+(n-sz[v]);

        dfs2(v,u);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    g.resize(n+1);
    sz.resize(n+1);
    ans.resize(n+1);
    depth.resize(n+1);

    for (int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs1(1,0);
    dfs2(1,0);

    for (int i=1;i<=n;i++){
        if (i!=1) cout<<' ';
        cout<<ans[i];
    }
    cout<<'\n';
    return 0;
}