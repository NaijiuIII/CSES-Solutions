#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;

int farnode;
int maxdepth;

void dfs(int u,int fa,int depth){
    if (depth>maxdepth){
        maxdepth=depth;
        farnode=u;
    }

    for (int v:g[u]){
        if (v==fa) continue;
        dfs(v,u,depth+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    g.resize(n+1);
    
    for (int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    maxdepth=-1;
    dfs(1,0,0);

    maxdepth=-1;
    int a=farnode;
    dfs(a,0,0);

    cout<<maxdepth<<'\n';
    return 0;
}

