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

    long long ans=0;

    long long sum=0;
    int l=0;
    for (int r=0;r<n;r++){
        sum+=a[r];
        if (sum>x){
            while (sum>x&&l<r){
                sum-=a[l];
                l++;
            }
        }

        if (sum==x){
            ans++;
        }
    }

    cout<<ans<<'\n';
    return 0; 
}