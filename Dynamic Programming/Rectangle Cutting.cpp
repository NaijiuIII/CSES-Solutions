#include <bits/stdc++.h>
using namespace std;
 


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b;
    cin>>a>>b;

    vector<vector<long long>> dp(a+1,vector<long long>(b+1,1e18));
    for (int i=1;i<=a;i++){
        for (int j=1;j<=b;j++){
            if (i==j) dp[i][j]=0;
            else{
                for (int k=1;k<=i/2;k++){
                    dp[i][j]=min(dp[i][j],dp[i-k][j]+dp[k][j]+1);
                }

                for (int k=1;k<=j/2;k++){
                    dp[i][j]=min(dp[i][j],dp[i][j-k]+dp[i][k]+1);
                }
            }
        }
    }

    cout<<dp[a][b]<<'\n';
    return 0; 
}