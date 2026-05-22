#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<pair<int,long long>>> g(n+1);

    for (int i=0;i<m;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    }

    priority_queue<pair<long long,int>,
    vector<pair<long long,int>>,greater<pair<long long,int>>> q;
    q.push({0,1});

    vector<int> cnt(n+1,0);
    vector<long long> ans;

    while (!q.empty()){
        auto [d,u]=q.top();
        q.pop();

        cnt[u]++;
        if (cnt[u]>k) continue;

        if (u==n){
            ans.push_back(d);
            if (ans.size()==k) break;
        }

        for (auto [v,w]:g[u]){
            q.push({d+w,v});
        }
    }

    for (int i=0;i<k;i++){
        if (i) cout<<' ';
        cout<<ans[i];
    }
    return 0;
}