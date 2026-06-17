#include <bits/stdc++.h>
using namespace std;

void dfs(int u,int fa,auto &up,auto &depth,auto &g){
    for (int v:g[u]){
        if (v==fa) continue;
        depth[v]=depth[u]+1;
        up[0][v]=u;

        dfs(v,u,up,depth,g);
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;
    vector<vector<int>> g(n+1);

    for (int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    const int log=20;
    vector<int> depth(n+1,0);
    vector<vector<int>> up(log,vector<int>(n+1,0));

    depth[1]=0;
    dfs(1,0,up,depth,g);

    for (int j=1;j<log;j++){
        for (int i=1;i<=n;i++){
            up[j][i]=up[j-1][up[j-1][i]];
        }
    }

    auto jump=[&](int x,int k){
        for (int j=0;j<log;j++){
            if ((k>>j)&1){
                x=up[j][x];
            }
        }
        return x;
    };

    auto lca=[&](int a,int b){
        if (depth[a]<depth[b]) swap(a,b);

        a=jump(a,depth[a]-depth[b]);
        if (a==b) return a;

        for (int j=log-1;j>=0;j--){
            if (up[j][a]!=up[j][b]){
                a=up[j][a];
                b=up[j][b];
            }
        }

        return up[0][a];
    };

    while (q--){
        int a,b;
        cin>>a>>b;

        cout<<depth[a]+depth[b]-2*depth[lca(a,b)]<<'\n';
    }
    return 0;
}