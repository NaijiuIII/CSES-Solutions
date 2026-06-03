#include <bits/stdc++.h>
using namespace std;

struct edge{
    int to,rev;
    int cap;
    int ori;
};

int n,m;
vector<vector<edge>> g;
vector<int> level;
vector<int> p;
vector<pair<int,int>> edges;

void addedge(int u,int v){
    edge a={v,g[v].size(),1,1};
    edge b={u,g[u].size(),0,0};

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

bool findpath(int u,vector<int> &path,vector<int> &vis){
    if (u==n) return true;

    vis[u]=1;

    for (auto &e:g[u]){
        int v=e.to;

        if (!e.ori) continue;
        if (e.cap!=0) continue;
        if (vis[v]) continue;

        path.push_back(v);
        if (findpath(v,path,vis)){
            e.cap=1;
            return true;
        }

        path.pop_back();
    }

    return false;

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

    cout<<ans<<'\n';

    for (int i=0;i<ans;i++){
        vector<int> path,vis(n+1,0);

        path.push_back(1);
        findpath(1,path,vis);

        cout<<path.size()<<'\n';

        for (int j=0;j<path.size();j++){
            if (j) cout<<' ';
            cout<<path[j];
        }
        cout<<'\n';
    }
    return 0;
}