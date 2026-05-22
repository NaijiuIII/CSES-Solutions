#include <bits/stdc++.h>
using namespace std;

int st=-1,ed=-1;

bool dfs(int u,const auto&g,auto &pre,auto &vis){
    vis[u]=1;

    for (int v:g[u]){
        if (vis[v]==0){
            pre[v]=u;
            if(dfs(v,g,pre,vis)) return true;
        }
        else if (vis[v]==1){
            st=v;
            ed=u;
            return true;
        }
    }

    vis[u]=2;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    vector<vector<int>> g(n+1);
    vector<int> vis(n+1,0);
    vector<int> pre(n+1,-1);
 
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
    }

    for (int i=1;i<=n;i++){
        if (vis[i]==0){
            if(dfs(i,g,pre,vis)) break;
        }
    }

    if (st==-1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

    vector<int> ans;
    ans.push_back(st);

    int cur=ed;
    while (cur!=st){
        ans.push_back(cur);
        cur=pre[cur];
    }
    ans.push_back(st);
    reverse(ans.begin(),ans.end());

    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();i++){
        if (i) cout<<' ';
        cout<<ans[i];
    }
    cout<<'\n';
    return 0;
}