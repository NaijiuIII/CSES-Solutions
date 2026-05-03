#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin>>t;
    long long mod=1e9+7;
 
    vector<long long> dp(1e6+1,0);
    dp[1]=2;
    dp[2]=8;
    for (int i=3;i<=1e6;i++){
        dp[i]=(6*dp[i-1]-7*dp[i-2])%mod;
        if (dp[i]<0) dp[i]+=mod;
    }
 
    while (t--){
        int q;
        cin>>q;
        cout<<dp[q]<<'\n';
    }
 
    return 0;
}