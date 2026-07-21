#include <bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;

long long qpow(long long a,long long b){
    long long ans=1;

    while (b>0){
        if (b&1) {
            ans=ans*a%mod;
        }

        a=a*a%mod;
        b>>=1;
    }
    return ans;
}

long long phi(long long x){
    long long ans=x;

    for (long long i=2;i*i<=x;i++){
        if (x%i!=0) continue;

        ans=ans/i*(i-1);
        while (x%i==0) x/=i;
    }

    if (x>1){
        ans=ans/x*(x-1);
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n,m;
    cin>>n>>m;

    long long sum=0;

    for (long long d=1;d*d<=n;d++){
        if (n%d!=0) continue;

        long long contri=phi(d)*qpow(m,n/d)%mod;
        sum=(sum+contri)%mod;

        long long other=n/d;

        if (other!=d){
            contri=phi(other)*qpow(m,n/other)%mod;
            sum=(sum+contri)%mod;
        }
    }

    long long invn=qpow(n,mod-2);
    long long ans=sum*invn%mod;

    cout<<ans<<'\n';
    return 0;
}