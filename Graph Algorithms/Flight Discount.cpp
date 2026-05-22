#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,long long>>> g(n+1);
    for (int i=0;i<m;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;

        g[a].push_back({b,c});
    }

    vector<vector<long long>> dp(n+1,vector<long long>(2,4e18));
    dp[1][0]=0;

    struct node{
        long long d;
        int u,used;

        bool operator>(const node&k) const {
            return d>k.d;
        }
    };

    priority_queue<node,vector<node>,greater<node>> q;
    q.push({0,1,0});

    while (!q.empty()){
        auto cur=q.top();
        q.pop();

        if (dp[cur.u][cur.used]!=cur.d) continue;

        for (auto [v,cost]:g[cur.u]){
            if (cur.used==1){
                if (dp[v][1]>dp[cur.u][1]+cost){
                    dp[v][1]=dp[cur.u][1]+cost;
                    q.push({dp[v][1],v,1});
                }
            }
            else{
                if (dp[v][0]>dp[cur.u][0]+cost){
                    dp[v][0]=dp[cur.u][0]+cost;
                    q.push({dp[v][0],v,0});
                }
                if (dp[v][1]>dp[cur.u][0]+cost/2){
                    dp[v][1]=dp[cur.u][0]+cost/2;
                    q.push({dp[v][1],v,1});
                }
            }
        }
    }

    cout<<dp[n][1]<<'\n';
    return 0;
}