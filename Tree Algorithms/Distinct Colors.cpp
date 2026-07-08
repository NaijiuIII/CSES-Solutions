#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> c;
vector<vector<int>> g;
vector<int> ans;
vector<set<int>> bag;

void dfs(int u,int fa){
    bag[u].insert(c[u]);

    for (int v:g[u]){
        if (v==fa) continue;

        dfs(v,u);

        if (bag[u].size()<bag[v].size()) swap(bag[u],bag[v]);

        for (int x:bag[v]) bag[u].insert(x);

        bag[v].clear();
    }

    ans[u]=bag[u].size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    c.assign(n+1,0);
    g.resize(n+1);
    ans.assign(n+1,0);
    bag.resize(n+1);

    for (int i=1;i<=n;i++){
        cin>>c[i];
    }

    for (int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1,0);

    for (int i=1;i<=n;i++){
        if (i!=1) cout<<' ';
        cout<<ans[i];
    }
    cout<<'\n';
    return 0;
}