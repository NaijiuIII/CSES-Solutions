#include <bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;

long long qpow(long long a,long long b){
    long long ans=1;

    while (b){
        if (b&1){
            ans=ans*a%mod;
        }

        a=a*a%mod;
        b>>=1;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<long long> fac(1e6+1,1);
    vector<long long> invfac(1e6+1,1);

    for (int i=1;i<=1e6;i++){
        fac[i]=fac[i-1]*i%mod;
        invfac[i]=qpow(fac[i],mod-2);
    }

    while (n--){
        long long a,b;
        cin>>a>>b;

        long long ans=fac[a];
        ans=ans*invfac[b]%mod;
        ans=ans*invfac[a-b]%mod;

        cout<<ans<<'\n';
    }
    return 0;
}