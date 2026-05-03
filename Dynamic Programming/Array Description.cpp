#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n,m;
    cin>>n>>m;
 
    long long mod=1e9+7;
    vector<vector<long long>> dp(n,vector<long long>(m+2,0));
    vector<long long> x(n);
    for (int i=0;i<n;i++){
        cin>>x[i];
        if (x[i]!=0) dp[i][x[i]]++;
        else{
            for (int j=1;j<=m;j++) dp[i][j]++;
        }
    }
    
    for (int i=1;i<n;i++){
        for (int j=1;j<=m;j++){
            if (x[i]!=0&&x[i]!=j) continue;
            dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]+dp[i-1][j+1])%mod;           
        }
    }

    long long res=0;
    for (int i=1;i<=m;i++) res=(res+dp[n-1][i])%mod;
    cout<<res<<'\n';
    return 0;
}