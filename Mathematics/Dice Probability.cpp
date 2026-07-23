#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,a,b;
    cin>>n>>a>>b;

    vector<long double> dp(6*n+1);
    vector<long double> ndp(6*n+1);

    dp[0]=1;

    for (int i=1;i<=n;i++){
        fill(ndp.begin(),ndp.end(),0);

        for (int j=0;j<=6*(i-1);j++){
            for (int x=1;x<=6;x++){
                ndp[j+x]+=dp[j]/6.0L;
            }
        }

        dp.swap(ndp);
    }

    long double ans=0;

    for (int i=a;i<=b;i++){
        ans+=dp[i];
    }

    cout<<fixed<<setprecision(6)<<ans<<'\n';
    return 0;
}