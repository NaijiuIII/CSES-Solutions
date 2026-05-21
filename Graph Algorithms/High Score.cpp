#include <bits/stdc++.h>
using namespace std;

struct edge{
    int a,b;
    long long w;
};

void dfs(auto &can,auto &rev,int u){
    can[u]=1;

    for (int v:rev[u]){
        if (!can[v]){
            dfs(can,rev,v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    vector<edge> e;

    vector<vector<int>> rev(n+1);

    for (int i=0;i<m;i++){
        int a,b;
        long long x;
        cin>>a>>b>>x;

        e.push_back({a,b,-x});
        rev[b].push_back(a);
    }

    vector<int> can(n+1,0);

    dfs(can,rev,n);

    vector<long long> dist(n+1,1e18);
    dist[1]=0;

    for (int i=1;i<n;i++){
        bool change=false;

        for (auto ei:e){
            if (dist[ei.a]==1e18) continue;

            if (dist[ei.b]>dist[ei.a]+ei.w){
                dist[ei.b]=dist[ei.a]+ei.w;
                change=true;
            }
        }

        if (!change){
            break;
        }
    }

    for (auto ei:e){
        if (dist[ei.a]==1e18) continue;

        if (dist[ei.b]>dist[ei.a]+ei.w){
            if (can[ei.b]){
                cout<<-1<<'\n';
                return 0;
            }
        }
    }

    cout<<-dist[n]<<'\n';
    return 0;
}