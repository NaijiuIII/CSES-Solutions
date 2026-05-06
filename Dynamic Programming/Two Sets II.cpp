#include <bits/stdc++.h>
using namespace std;
 


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    const long long mod=1e9+7;

    int n;
    cin>>n;
    long long k=n*(n+1)/4;

    vector<long long> dp(k+1,0);
    dp[0]=1;
    if (n*(n+1)/2%2==1){
        cout<<0<<'\n';
        return 0;
    }

    for (int i=1;i<n;i++){
        for (int j=k;j>=i;j--){
            dp[j]=(dp[j]+dp[j-i])%mod;
        }
    }

    cout<<dp[k]<<'\n';
    return 0;  
}