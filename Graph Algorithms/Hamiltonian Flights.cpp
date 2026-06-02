#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    const int mod=1e9+7;

	int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n);
    vector<vector<int>> dp((1<<n),vector<int>(n,0));
    dp[1][0]=1;

    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;

        g[a].push_back(b);
    }

    for (int mask=0;mask<(1<<n);mask++){
        for (int u=0;u<n;u++){
            if (u==n-1&&mask!=(1<<n)-1) continue;
            if (dp[mask][u]==0) continue;
            if (!(mask&(1<<u))) continue;

            for (int v:g[u]){
                if (mask&(1<<v)) continue;

                int nmask=mask|(1<<v);
                dp[nmask][v]=(dp[nmask][v]+dp[mask][u])%mod;
            }
        }
    }

    cout<<dp[(1<<n)-1][n-1]<<'\n';
    return 0;
}