#include <bits/stdc++.h>
using namespace std;

const long long mod1=1e9+7;
const long long mod2=1e9+6;

long long qpow(long long a,long long b,const long long mod){
    long long ans=1;
    a%=mod;

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
    vector<long long> p(n),k(n);
    for (int i=0;i<n;i++){
        cin>>p[i]>>k[i];
    }

    long long ans1=1;
    for (int i=0;i<n;i++){
        ans1=ans1*(k[i]+1)%mod1;
    }

    long long ans2=1;
    for (int i=0;i<n;i++){
        long long up=(qpow(p[i],k[i]+1,mod1)-1+mod1)%mod1;
        long long down=qpow(p[i]-1,mod1-2,mod1);

        long long sum=up*down%mod1;
        ans2=ans2*sum%mod1;
    }

    long long ans3=1;
    long long cnt=1;

    for (int i=0;i<n;i++){
        long long s;

        if (k[i]%2==0){
            s=(k[i]/2)%mod2;
            s=s*(((k[i]+1))%mod2)%mod2;
        }
        else{
            s=(k[i])%mod2;
            s=s*(((k[i]+1)/2)%mod2)%mod2;
        }

        long long e=cnt*s%mod2;

        ans3=qpow(ans3,k[i]+1,mod1)*qpow(p[i],e,mod1)%mod1;
        cnt=(cnt*(k[i]+1)%mod2)%mod2;
    }

    cout<<ans1<<' '<<ans2<<' '<<ans3<<'\n';
    return 0;
}