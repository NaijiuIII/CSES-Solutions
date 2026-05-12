#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,x;
    cin>>n>>x;

    vector<long long> w(n);
    for (int i=0;i<n;i++) cin>>w[i];

    int m=1<<n;

    vector<pair<int,long long>> dp(m,{n+1,0});

    dp[0]={1,0};

    for (int s=0;s<m;s++){
        for (int i=0;i<n;i++){
            if (s&(1<<i)) continue;

            int ns=s|(1<<i);
            int cnt=dp[s].first;
            long long sum=dp[s].second;

            if (sum+w[i]<=x) sum+=w[i];
            else{
                cnt++;
                sum=w[i];
            }

            dp[ns]=min(dp[ns],{cnt,sum});
        }
    }

    cout<<dp[m-1].first<<'\n';
    return 0;
}