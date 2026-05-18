#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<char> vis;
vector<int> p,ans;

bool dfs(int u,int fa){
    vis[u]=true;
    p[u]=fa;

    for (int v:g[u]){
        if (v==fa) continue;

        if (vis[v]){
            ans.push_back(v);
            int x=u;
            while (x!=v){
                ans.push_back(x);
                x=p[x];
            }
            ans.push_back(v);
            return true;
        }

        if (dfs(v,u)) return true;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    g.resize(n+1);
    vis.assign(n+1,false);
    p.assign(n+1,-1);

    int m;
    cin>>m;
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            if (dfs(i,-1)){
                cout<<ans.size()<<'\n';
                for (int x:ans) cout<<x<<' ';
                cout<<'\n';
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}