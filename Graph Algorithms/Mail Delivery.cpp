#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<pair<int,int>>> g;
vector<int> ans;
vector<int> deg;
vector<int> p;
vector<char> vis;

void dfs(int u){
    while (p[u]<g[u].size()){
        auto [v,id]=g[u][p[u]];
        p[u]++;

        if (vis[id]) continue;

        vis[id]=true;
        dfs(v);
    }

    ans.push_back(u);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin>>n>>m;
    g.resize(n+1);
    vis.assign(m+1,false);
    deg.assign(n+1,0);
    p.assign(n+1,0);
    
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back({b,i});
        g[b].push_back({a,i});

        deg[a]++;
        deg[b]++;
    }

    for (int i=1;i<=n;i++){
        if (deg[i]%2==1){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }

    dfs(1);

    if (ans.size()!=m+1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

    for (int i=0;i<ans.size();i++){
        if (i) cout<<' ';
        cout<<ans[i];
    } 
    return 0;
}