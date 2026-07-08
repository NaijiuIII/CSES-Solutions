#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> sz;
int ans=1;

void dfs(int u,int fa){
    sz[u]=1;

    int mx=0;

    for (int v:g[u]){
        if (v==fa) continue;

        dfs(v,u);

        sz[u]+=sz[v];
        mx=max(mx,sz[v]);
    }

    mx=max(mx,n-sz[u]);

    if (mx<=n/2){
        ans=u;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    g.resize(n+1);
    sz.assign(n+1,0);

    for (int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1,0);

    cout<<ans<<'\n';
    return 0;
}