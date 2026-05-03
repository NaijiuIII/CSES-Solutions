#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin>>n;
 
    long long mod=1e9+7;
 
    vector<long long> dp(n+1,0);
    dp[0]=1;
    for (int i=1;i<=n;i++){
        for (int j=i-6;j<i;j++){
            if (j<0) continue;
            dp[i]=(dp[i]+dp[j])%mod;
        }
    }
    cout<<dp[n]<<'\n';
    return 0;
}