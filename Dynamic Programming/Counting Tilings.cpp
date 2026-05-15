#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> dp,ndp;
const int mod=1e9+7;

void dfs(int row,int cur,int nxt,int val){
    if (row==n){
        ndp[nxt]=(ndp[nxt]+val)%mod;
        return;
    }

    if (cur&(1<<row)){
        dfs(row+1,cur,nxt,val);
        return;
    }

    dfs(row+1,cur|(1<<row),nxt|(1<<row),val);

    if (row+1<n&&!(cur&(1<<(row+1)))){
        dfs(row+2,cur|(1<<row)|(1<<(row+1)),nxt,val);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;

    int s=1<<n;
    dp.assign(s,0);
    ndp.assign(s,0);

    dp[0]=1;

    for (int col=0;col<m;col++){
        fill(ndp.begin(),ndp.end(),0);

        for (int mask=0;mask<s;mask++){
            if (dp[mask]) dfs(0,mask,0,dp[mask]);
        }

        dp=ndp;
    }

    cout<<dp[0]<<'\n';
    return 0;
}