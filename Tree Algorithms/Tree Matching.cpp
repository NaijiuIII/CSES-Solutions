#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> dp0,dp1;

void dfs(int u,int fa){
    for (int v:g[u]){
        if (v==fa) continue;
        dfs(v,u);
    }

    dp0[u]=0;
    for (int v:g[u]){
        if (v==fa) continue;
        dp0[u]+=max(dp0[v],dp1[v]);
    }

    dp1[u]=0;
    for (int v:g[u]){
        if (v==fa) continue;
        int cur=dp0[u];
        cur-=max(dp0[v],dp1[v]);

        cur+=dp0[v]+1;
        dp1[u]=max(dp1[u],cur);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    g.resize(n+1);
    dp0.assign(n+1,0);
    dp1.assign(n+1,0);

    for (int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1,0);

    cout<<max(dp0[1],dp1[1])<<'\n';
    return 0;
}

