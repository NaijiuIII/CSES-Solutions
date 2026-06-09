#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;

    vector<pair<int,int>> movie(n);
    for (int i=0;i<n;i++){
        cin>>movie[i].first>>movie[i].second;
    }

    vector<int> best(1e6+2,1e9);
    vector<int> nxt(1e6+2,1e9);

    for (int i=0;i<n;i++){
        best[movie[i].first]=min(best[movie[i].first],movie[i].second);
    }

    for (int t=1e6;t>=1;t--){
        nxt[t]=min(best[t],nxt[t+1]);
    }

    vector<vector<int>> up(21,vector<int>(1e6+1,1e9));

    for (int t=1;t<=1e6;t++){
        up[0][t]=nxt[t];
    }

    for (int k=1;k<21;k++){
        for (int t=1;t<=1e6;t++){
            if (up[k-1][t]<=1e6) up[k][t]=up[k-1][up[k-1][t]];
        }
    }

    while (q--){
        int a,b;
        cin>>a>>b;
        int cur=a;
        int ans=0;

        for (int k=20;k>=0;k--){
            if (cur<=1e6&&up[k][cur]<=b){
                ans+=1<<k;
                cur=up[k][cur];
            }
        }

        cout<<ans<<'\n';
    }
    return 0;
}