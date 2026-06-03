#include <bits/stdc++.h>
using namespace std;

struct edge{
    int to,rev;
    int cap;
};

int n,m;
vector<vector<edge>> g;
vector<int> level;
vector<int> p;
vector<pair<int,int>> edges;

void addedge(int u,int v){
    edge a={v,g[v].size(),1};
    edge b={u,g[u].size(),1};

    g[u].push_back(a);
    g[v].push_back(b);
}

bool bfs(int s,int t){
    level.assign(n+1,-1);

    queue<int> q;
    q.push(s);
    level[s]=0;

    while (!q.empty()){
        int u=q.front();
        q.pop();

        for (auto e:g[u]){
            int v=e.to;
            if (level[v]==-1&&e.cap>0){
                level[v]=level[u]+1;
                q.push(v);
            }
        }
    }

    return level[t]!=-1;
}

int dfs(int u,int t,int flow){
    if (u==t) return flow;

    for (int &i=p[u];i<g[u].size();i++){
        auto &e=g[u][i];
        int v=e.to;

        if (level[v]==level[u]+1 && e.cap>0){
            int pushed=dfs(v,t,min(flow,e.cap));

            if (pushed>0){
                e.cap-=pushed;
                g[v][e.rev].cap+=pushed;

                return pushed;
            }
        }
    }
    return 0;
}

int dinic(int s,int t){
    int ans=0;

    while (bfs(s,t)){
        p.assign(n+1,0);

        while (1){
            long long pushed=dfs(s,t,1e9);
            ans+=pushed;
            if (pushed==0) break;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    g.resize(n+1);

    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        addedge(a,b);

        edges.push_back({a,b});
    }

    int ans=dinic(1,n);

    vector<int> vis(n+1,0);
    queue<int> q;

    vis[1]=1;
    q.push(1);

    while (!q.empty()){
        int u=q.front();
        q.pop();

        for (auto e:g[u]){
            int v=e.to;

            if (!vis[v] && e.cap>0){
                vis[v]=1;
                q.push(v);
            }
        }
    }

    vector<pair<int,int>> cut;

    for (auto [a,b] : edges){
        if (vis[a]!=vis[b]){
            cut.push_back({a,b});
        }
    }

    cout<<ans<<'\n';
    for (auto [a,b]:cut){
        cout<<a<<' '<<b<<'\n';
    }
    return 0;
}