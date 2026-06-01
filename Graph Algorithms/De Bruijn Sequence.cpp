#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<pair<int,int>>> g;
string ans;
vector<int> p;

void dfs(int u){
    while (p[u]<g[u].size()){
        auto [v,id]=g[u][p[u]];
        p[u]++;

        dfs(v);
        ans.push_back((char)('0'+id));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin>>n>>m;
    
    if (n==1){
        cout<<"01\n";
        return 0;
    }

    int nodes=1<<(n-1);

    int mask=nodes-1;

    g.resize(nodes);
    p.assign(nodes,0);

    for (int u=0;u<nodes;u++){
        for (int id=0;id<=1;id++){
            int v=((u<<1)&mask)|id;

            g[u].push_back({v,id});
        }
    }

    dfs(0);

    reverse(ans.begin(),ans.end());

    for (int i=0;i<n-1;i++){
        cout<<'0';
    }
    cout<<ans<<'\n';
    return 0;
}