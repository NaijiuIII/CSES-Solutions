#include <bits/stdc++.h>
using namespace std;

int n,m,k;
vector<int> match;
vector<vector<int>> g;
vector<int> vis;

bool dfs(int u){
    for (int v:g[u]){
        if (vis[v]) continue;
        vis[v]=1;

        if (match[v]==0||dfs(match[v])){
            match[v]=u;
            return true;
        }
    }

    return false;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>k;
    match.assign(m+1,0);
    g.resize(n+1);

    for (int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }

    int ans=0;
    for (int i=1;i<=n;i++){
        vis.assign(m+1,0);

        if (dfs(i)){
            ans++;
        }
    }

    cout<<ans<<'\n';
    for (int i=1;i<=m;i++){
        if (match[i]!=0){
            cout<<match[i]<<' '<<i<<'\n';
        }
    }
    return 0;
}