#include <bits/stdc++.h>
using namespace std;

struct range{
    long long a,b;
    long long p;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<range> pro(n);

    for (int i=0;i<n;i++){
        cin>>pro[i].a>>pro[i].b>>pro[i].p;
    }

    sort(pro.begin(),pro.end(),[](auto &x,auto &y){
        if (x.b!=y.b) return x.b<y.b;
        return x.p>y.p;
    });

    vector<long long> dp(n,0);
    dp[0]=pro[0].p;
    for (int i=1;i<n;i++){

        int l=0,r=i;
        int pos=-1;

        while (l<=r){
            int mid=(l+r)/2;
            if (pro[mid].b<pro[i].a){
                pos=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        if (pos==-1){
            dp[i]=max(dp[i-1],pro[i].p);
            continue;
        }
        dp[i]=max(dp[pos]+pro[i].p,dp[i-1]);
    }

    cout<<dp[n-1]<<'\n';
    return 0;
}