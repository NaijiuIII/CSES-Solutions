#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> color;
bool possible=true;

void dfs(int cur){
    if (!possible) return;

    for (int x:g[cur]){
        if (color[x]==0){
            color[x]=(color[cur]==1 ? 2:1);
            dfs(x);
        }

        if (color[x]==color[cur]) possible=false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    g.resize(n+1);
    color.assign(n+1,0);
    
    int m;
    cin>>m;
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i=1;i<=n;i++){
        if (color[i]==0){
            color[i]=1;
            dfs(i);
        }
    }

    if (!possible){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        for (int i=1;i<=n;i++){
            if (i!=1) cout<<' ';
            cout<<color[i];
        }
        cout<<'\n';
    }
    return 0;
}