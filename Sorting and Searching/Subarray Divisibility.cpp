#include <bits/stdc++.h>
using namespace std;
 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<long long> a(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }

    long long ans=0;
    long long sum=0;
    vector<long long> mod(n+1,0);
    mod[0]=1;

    for (int r=0;r<n;r++){
        sum+=a[r];
        int k=sum%n;
        if (k<0) k+=n;
        ans+=mod[k];
        mod[k]++;
    }

    cout<<ans<<'\n';
    return 0; 
}