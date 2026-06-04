#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;

    vector<long long> x(n);
    vector<long long> pre(n+1,0);

    for (int i=0;i<n;i++){
        cin>>x[i];
        pre[i+1]=pre[i]+x[i];
    }

    while (q--){
        int a,b;
        cin>>a>>b;

        cout<<pre[b]-pre[a-1]<<'\n';
    }
    return 0;
}