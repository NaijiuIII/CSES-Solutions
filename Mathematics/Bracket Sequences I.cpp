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

    vector<long long> fac(1e6+1,1);
    vector<long long> invfac(1e6+1,1);

    for (int i=1;i<=1e6;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    invfac[1e6]=qpow(fac[1e6],mod-2);
    for (int i=1e6;i>=1;i--){
        invfac[i-1]=i*invfac[i]%mod;
    }

    int n;
    cin>>n;

    if (n&1){
        cout<<0<<'\n';
        return 0;
    }

    long long m=n/2;

    long long ans=fac[n]*invfac[m]%mod*invfac[m+1]%mod;

    cout<<ans<<'\n';

    return 0;
}