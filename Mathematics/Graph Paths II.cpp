#include <bits/stdc++.h>
using namespace std;

const long long INF=2e18;

int n;

struct M{
    vector<vector<long long>> a;

    M(){
        a.assign(n,vector<long long>(n,INF));
    }
};

M mul(const M&x,const M&y){
    M z;

    for (int i=0;i<n;i++){
        for (int k=0;k<n;k++){
            if (x.a[i][k]==INF) continue;

            for (int j=0;j<n;j++){
                if (y.a[k][j]==INF) continue;

                z.a[i][j]=min(z.a[i][j],x.a[i][k]+y.a[k][j]);
            }
        }
    }

    return z;
}

M qpow(M a,long long b){
    M ans;

    for (int i=0;i<n;i++) ans.a[i][i]=0;

    while (b>0){
        if (b&1){
            ans=mul(ans,a);
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
        long long w;
        cin>>u>>v>>w;

        u--;
        v--;

        graph.a[u][v]=min(graph.a[u][v],w);
    }

    M ans=qpow(graph,k);

    long long res=ans.a[0][n-1];
    if (res==INF) cout<<-1<<'\n';
    else cout<<res<<'\n';
    return 0;
}