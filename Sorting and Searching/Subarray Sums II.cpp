#include <bits/stdc++.h>
using namespace std;
 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    long long x;
    cin>>x;
    vector<long long> a(n);

    for (int i=0;i<n;i++) cin>>a[i];

    map<long long,long long> m;
    m[0]=1;
    long long sum=0;
    long long ans=0;
    
    for (int r=0;r<n;r++){
        sum+=a[r];
        ans+=m[sum-x];
        m[sum]++;
    }

    cout<<ans<<'\n';
    return 0; 
}