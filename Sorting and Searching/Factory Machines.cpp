#include <bits/stdc++.h>
using namespace std;
 
bool check(const vector<long long> k,long long x,long long t){
    long long cnt=0;
    for (long long mech:k){
        cnt+=x/mech;
        if (cnt>=t) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    long long t;
    cin>>t;
    vector<long long> k(n);
    for (int i=0;i<n;i++) cin>>k[i];

    long long l=1,r=1e18;
    long long ans=0;
    while (l<=r){
        long long mid=(l+r)/2;

        if (check(k,mid,t)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }

    cout<<ans<<'\n';
    return 0;
}