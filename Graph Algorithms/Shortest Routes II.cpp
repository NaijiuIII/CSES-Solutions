#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,q;
    cin>>n>>m>>q;

    vector<vector<long long>> dis(n+1,vector<long long>(n+1,1e18));
    for (int i=1;i<=n;i++) dis[i][i]=0;

    for (int i=0;i<m;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;

        dis[a][b]=min(dis[a][b],c);
        dis[b][a]=min(dis[a][b],c);
    }

    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }

    while (q--){
        int a,b;
        cin>>a>>b;
        
        if (dis[a][b]==1e18) cout<<-1<<'\n';
        else cout<<dis[a][b]<<'\n';
    }
    return 0;
}