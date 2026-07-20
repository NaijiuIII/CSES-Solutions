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

    long long n,m;
    cin>>n>>m;

    vector<long long> fac(2e6+1,1);
    vector<long long> invfac(2e6+1,1);

    for (int i=1;i<=2e6;i++){
        fac[i]=fac[i-1]*i%mod;
        invfac[i]=qpow(fac[i],mod-2);
    }
    cout<<fac[m+n-1]*invfac[n-1]%mod*invfac[m]%mod<<'\n';
    return 0;
}