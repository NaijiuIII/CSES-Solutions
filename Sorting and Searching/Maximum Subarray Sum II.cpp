#include <bits/stdc++.h>
using namespace std;
 


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,a,b;
    cin>>n>>a>>b;

    vector<long long> x(n);
    for (int i=0;i<n;i++){
        cin>>x[i];
    }

    vector<long long> pre(n+1);
    pre[0]=0;
    for (int i=1;i<=n;i++) pre[i]=pre[i-1]+x[i-1];

    multiset<long long> s;
    long long ans=-4e18;
    for (int r=a;r<=n;r++){
        s.insert(pre[r-a]);
        if (r-b-1>=0){
            s.erase(s.find(pre[r-b-1]));
        }

        ans=max(ans,pre[r]-*s.begin());
    }

    cout<<ans<<'\n';
    return 0; 
}