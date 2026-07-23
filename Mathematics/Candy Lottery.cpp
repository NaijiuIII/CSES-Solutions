#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    long double ans=0;

    for (int x=1;x<=k;x++){
        long double p=(long double)(x-1)/k;
        long double none=powl(p,n);
        ans+=1-none;
    }

    cout<<fixed<<setprecision(6)<<ans<<'\n';
    return 0;
}