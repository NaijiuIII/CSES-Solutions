#include <bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;
const long long inv2=(mod+1)/2;

long long sum(long long l,long long r){
    long long a=(l+r)%mod;
    long long b=(r-l+1)%mod;

    return a*b%mod*inv2%mod;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin>>n;

    long long ans=0;

    long long l=1,r;
    while (l<=n){
        long long q=n/l;
        r=n/q;

        long long s=sum(l,r);

        long long add=(q%mod)*s%mod;
        ans=(ans+add)%mod;
        l=r+1;
    }

    cout<<ans<<'\n';

    return 0;
}