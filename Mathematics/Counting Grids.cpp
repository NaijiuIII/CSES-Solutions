#include <bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;

long long qpow(long long a,long long b){
    long long ans=1;

    while (b>0){
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

    long long n;
    cin>>n;

    long long k=n*n;

    long long cnt0=k;
    long long cnt180=(k+1)/2;

    long long cnt90;
    if (n%2==0){
        cnt90=k/4;
    }
    else{
        cnt90=(k+4-1)/4;
    }

    long long sum=0;

    sum=(sum+qpow(2,cnt0))%mod;
    sum=(sum+qpow(2,cnt180))%mod;
    sum=(sum+2*qpow(2,cnt90))%mod;

    long long inv4=qpow(4,mod-2);
    cout<<sum*inv4%mod<<'\n';
    return 0;
}