#include <bits/stdc++.h>
using namespace std;

struct edge{
    int to;
    int rev;
    long long cap;
};

int n,m;
vector<vector<edge>> g;
vector<int> level;
vector<int> p;

void addedge(int u,int v,long long c){
    edge a={v,g[v].size(),c};
    edge b={u,g[u].size(),0};

    g[u].push_back(a);
    g[v].push_back(b);
}

bool bfs(int s,int t){
    level.assign(n+1,-1);

    queue<int> q;
    level[s]=0;
    q.push(s);

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

long long dfs(int u,int t,long long flow){
    if (u==t) return flow;

    for (int &i=p[u];i<g[u].size();i++){
        auto &e=g[u][i];
        int v=e.to;

        if (e.cap>0&&level[v]==level[u]+1){
            long long pushed=dfs(v,t,min(flow,e.cap));

            if (pushed>0){
                e.cap-=pushed;
                g[v][e.rev].cap+=pushed;

                return pushed;
            }
        }
    }
    return 0;
}

long long dinic(int s,int t){
    long long ans=0;

    while (bfs(s,t)){
        p.assign(n+1,0);

        while (1){
            long long pushed=dfs(s,t,1e18);
            if (pushed==0) break;

            ans+=pushed;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    g.assign(n+1,vector<edge>());

    for (int i=0;i<m;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;

        addedge(a,b,c);
    }

    cout<<dinic(1,n)<<'\n';
    return 0;
}