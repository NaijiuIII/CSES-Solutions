#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,long long>>> g(n+1);
    vector<long long> mindis(n+1,1e18);

    for (int i=0;i<m;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    }

    priority_queue<pair<long long,int>,vector<pair<long long,int>>
    ,greater<pair<long long,int>>> q;

    mindis[1]=0;
    q.push({0,1});

    while (!q.empty()){
        auto [dis,u]=q.top();
        q.pop();

        if (dis!=mindis[u]) continue;

        for (auto [nxt,d]:g[u]){
            if (mindis[nxt]<=dis+d) continue;
            mindis[nxt]=dis+d;

            q.push({dis+d,nxt});
        }
    }

    for (int i=0;i<n;i++){
        if (i) cout<<' ';
        cout<<mindis[i+1];
    }
    cout<<'\n';
    return 0;
}