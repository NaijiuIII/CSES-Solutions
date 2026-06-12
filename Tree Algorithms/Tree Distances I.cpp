#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;

pair<int,vector<int>> bfs(int s){
    vector<int> dist(n+1,-1);

    queue<int> q;
    q.push(s);
    dist[s]=0;

    while (!q.empty()){
        int u=q.front();
        q.pop();

        for (int v:g[u]){
            if (dist[v]!=-1) continue;

            dist[v]=dist[u]+1;
            q.push(v);
        }
    }

    int far=s;

    for (int i=1;i<=n;i++){
        if (dist[i]>dist[far]){
            far=i;
        }
    }

    return {far,dist};
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

    int A=bfs(1).first;
    auto p1=bfs(A);
    int B=p1.first;
    auto distA=p1.second;

    auto p2=bfs(B);
    auto distB=p2.second;

    for (int i=1;i<=n;i++){
        if (i!=1) cout<<' ';
        cout<<max(distA[i],distB[i]);
    }
    cout<<'\n';
    return 0;
}