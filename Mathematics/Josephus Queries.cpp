#include <bits/stdc++.h>
using namespace std;

long long solve(long long n,long long k){
    long long cnt=(n+1)/2;

    if (k<=cnt){
        auto ans=2*k;
        if (ans>n) ans-=n;
        return ans;
    }

    long long x=solve(n/2,k-cnt);

    if (n%2==0) return 2*x-1;
    return 2*x+1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin>>q;

    while (q--){
        long long n,k;
        cin>>n>>k;

        cout<<solve(n,k)<<'\n';
    }
    return 0;
}