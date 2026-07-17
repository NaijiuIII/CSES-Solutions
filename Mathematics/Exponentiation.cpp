#include <bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;

long long qpow(long long a,long long b){
    long long ans=1;

    a%=mod;

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

    int n;
    cin>>n;
    while (n--){
        long long a,b;
        cin>>a>>b;

        cout<<qpow(a,b)<<'\n';
    }
    return 0;
}