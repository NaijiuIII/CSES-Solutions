#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> x(n);
    int mx=0;
    for (int i=0;i<n;i++){
        cin>>x[i];
        mx=max(mx,x[i]);
    }

    vector<int> freq(mx+1,0);

    for (int i=0;i<n;i++) freq[x[i]]++;

    vector<long long> cnt(mx+1,0);

    for (int d=1;d<=mx;d++){
        for (int j=d;j<=mx;j+=d){
            cnt[d]+=freq[j];
        }
    }

    vector<long long> exact(mx+1,0);
    
    for (int d=mx;d>=1;d--){
        exact[d]=(cnt[d]*(cnt[d]-1))/2;

        for (int j=2*d;j<=mx;j+=d) exact[d]-=exact[j];
    }

    cout<<exact[1]<<'\n';
    return 0;
}