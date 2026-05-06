#include <bits/stdc++.h>
using namespace std;
 


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<long long> x(n);
    long long sum=0;
    vector<vector<long long>> dp(n,vector<long long>(n,0));
    
    for (int i=0;i<n;i++){
        cin>>x[i];
        sum+=x[i];
        dp[i][i]=x[i];
    }

    for (int len=2;len<=n;len++){
        for (int l=0;l+len-1<n;l++){
            int r=l+len-1;
            dp[l][r]=max(x[l]-dp[l+1][r],x[r]-dp[l][r-1]);
        }
    }

    cout<<(sum+dp[0][n-1])/2<<'\n';
    return 0;  
}