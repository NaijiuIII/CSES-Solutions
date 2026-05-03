#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n,x;
    cin>>n>>x;
    vector<int> c(n);
    for (int i=0;i<n;i++) cin>>c[i];
    sort(c.begin(),c.end());
 
    vector<int> dp(x+1,1e9);
    dp[0]=0;
    for (int i=1;i<=x;i++){
        for (int ci:c){
            if (i-ci>=0){
                dp[i]=min(dp[i],dp[i-ci]+1);
            }
        }
    }
    cout<<(dp[x]!=1e9?dp[x]:-1)<<'\n';
    return 0;
}