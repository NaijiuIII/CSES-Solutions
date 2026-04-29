#include <bits/stdc++.h>
using namespace std;
 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    long long t;
    long long sum=0,mx=0;

    for (int i=0;i<n;i++){
        cin>>t;
        sum+=t;
        mx=max(mx,t);
    }

    cout<<max(sum,2*mx)<<'\n';
    return 0; 
}