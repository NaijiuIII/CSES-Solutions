#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g;
vector<int> in,out,p;
vector<int> ans;

void dfs(int u){
    while (p[u]<g[u].size()){
        int v=g[u][p[u]];
        p[u]++;
        dfs(v);
    }

    ans.push_back(u);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin>>n>>m;
    g.resize(n+1);
    p.assign(n+1,0);
    in.assign(n+1,0);
    out.assign(n+1,0);

    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        out[a]++;
        in[b]++;
    }

    for (int i=1;i<=n;i++){
        bool judge=true;
        if (i==1&&out[i]!=in[i]+1) judge=false;
        else if (i==n&&in[i]!=out[i]+1) judge=false;
        else if (i!=1&&i!=n&&in[i]!=out[i]) judge=false;

        if (!judge){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }

    dfs(1);

    reverse(ans.begin(),ans.end());

    if (ans.size()!=m+1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

    for (int i=0;i<ans.size();i++){
        if (i) cout<<' ';
        cout<<ans[i];
    }
    cout<<'\n';
    return 0;
}