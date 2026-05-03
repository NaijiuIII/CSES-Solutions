#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    long long x;
    cin>>n>>x;
 
    long long mod=1e9+7;
 
    vector<long long> c(n);
    for (int i=0;i<n;i++) cin>>c[i];
    sort(c.begin(),c.end());
 
    vector<long long> dp(x+1,0);
    dp[0]=1;
 
    for (int i=1;i<=x;i++){
        for (int j:c){
            if (i-j>=0){
                dp[i]=(dp[i]+dp[i-j])%mod;
            }
        }
    }
 
    cout<<dp[x]<<'\n';
    return 0;
}