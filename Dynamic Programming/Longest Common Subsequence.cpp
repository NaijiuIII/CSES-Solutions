#include <bits/stdc++.h>
using namespace std;
 


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<long long> a(n);
    vector<long long> b(m);

    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<m;i++) cin>>b[i];

    vector<vector<long long>> dp(n+1,vector<long long>(m+1,0));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    } 

    vector<long long> ans;
    int i=n,j=m;

    while (i>0&&j>0){
        if (a[i-1]==b[j-1]){
            ans.push_back(a[i-1]);
            i--;
            j--;
        }
        else if (dp[i-1][j]>=dp[i][j-1]){
            i--;
        }
        else j--;
    }

    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();i++){
        if (i) cout<<' ';
        cout<<ans[i];
    }
    cout<<'\n';
    return 0; 
}