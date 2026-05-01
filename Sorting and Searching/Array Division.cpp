#include <bits/stdc++.h>
using namespace std;
 
bool check(const vector<long long>&a,int k,long long mx){
    int num=1;
    long long cur=0;

    for (int i=0;i<a.size();i++){
        if (a[i]>mx) return false;

        if (cur+a[i]<=mx){
            cur+=a[i];
        }
        else{
            num++;
            cur=a[i];
        }
    }

    if (num<=k) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    vector<long long> a(n);
    long long sum=0;
    for (int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }

    long long l=0,r=sum;
    long long ans=0;
    while (l<=r){
        long long mid=(l+r)/2;

        if (check(a,k,mid)){
            r=mid-1;
            ans=mid;
        }
        else l=mid+1;
    }

    cout<<ans<<'\n';
    return 0; 
}