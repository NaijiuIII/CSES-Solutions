#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    vector<vector<int>> g(n+1);
    vector<int> deg(n+1,0);
    queue<int> q;
    vector<int> ans;
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        deg[b]++;
    }

    for (int i=1;i<=n;i++){
        if (deg[i]==0) q.push(i);
    }

    while (!q.empty()){
        int u=q.front();
        q.pop();

        ans.push_back(u);
        for (int v:g[u]){
            deg[v]--;
            if (deg[v]==0) q.push(v);
        }
    }

    if (ans.size()!=n) {
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