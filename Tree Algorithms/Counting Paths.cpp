#include <bits/stdc++.h>
using namespace std;

const int L=20;

int n,m;
vector<int> depth;
vector<vector<int>> up;
vector<vector<int>> g;
vector<long long> cnt;

void dfs(int u,int fa){
    up[0][u]=fa;

    for (int j=1;j<L;j++){
        up[j][u]=up[j-1][up[j-1][u]];
    }

    for (int v:g[u]){
        if (v==fa) continue;
        depth[v]=depth[u]+1;
        dfs(v,u);
    }
}

int lca(int a,int b){
    if (depth[a]<depth[b]) swap(a,b);

    int d=depth[a]-depth[b];

    for (int j=0;j<L;j++){
        if ((d>>j)&1){
            a=up[j][a];
        }
    }

    if (a==b) return a;

    for (int j=L-1;j>=0;j--){
        if (up[j][a]!=up[j][b]){
            a=up[j][a];
            b=up[j][b];
        }
    }

    return up[0][a];
}

void dfs2(int u,int fa){
    for (int v:g[u]){
        if (v==fa) continue;

        dfs2(v,u);

        cnt[u]+=cnt[v];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    depth.assign(n+1,0);
    g.resize(n+1);
    up.assign(L,vector<int>(n+1,0));
    cnt.assign(n+1,0);

    for (int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1,0);

    while (m--){
        int a,b;
        cin>>a>>b;

        int l=lca(a,b);
        int p=up[0][l];

        cnt[a]++,cnt[b]++;
        cnt[l]--,cnt[p]--;
    }

    dfs2(1,0);

    for (int i=1;i<=n;i++){
        if (i!=1) cout<<' ';
        cout<<cnt[i];
    }
    cout<<'\n';
    return 0;
}