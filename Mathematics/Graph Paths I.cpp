#include <bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;

int n;

struct M{
    vector<vector<long long>> a;

    M(){
        a.assign(n,vector<long long>(n,0));
    }
};

M mul(const M&x,const M&y){
    M z;

    for (int i=0;i<n;i++){
        for (int k=0;k<n;k++){
            if (x.a[i][k]==0) continue;

            for (int j=0;j<n;j++){
                z.a[i][j]+=x.a[i][k]*y.a[k][j]%mod;
                z.a[i][j]%=mod;
            }
        }
    }

    return z;
}

M qpow(M a,long long b){
    M ans;

    for (int i=0;i<n;i++) ans.a[i][i]=1;

    while (b>0){
        if (b&1){
            ans=mul(a,ans);
        }
        a=mul(a,a);
        b>>=1;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m;
    long long k;
    cin>>n>>m>>k;

    M graph;

    for (int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        u--;
        v--;

        graph.a[u][v]++;
        graph.a[u][v]%=mod;
    }

    M ans=qpow(graph,k);

    cout<<ans.a[0][n-1]<<'\n';
    return 0;
}