#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    struct edge{
        int a,b;
        long long c;
    };

    vector<edge> edges;
    for (int i=0;i<m;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }

    vector<long long> dist(n+1,0);
    vector<int> pre(n+1,-1);

    int x=-1;

    for (int i=1;i<=n;i++){
        x=-1;

        for (auto [a,b,c]:edges){
            if (dist[b]>dist[a]+c){
                dist[b]=dist[a]+c;
                pre[b]=a;
                x=b;
            }
        }
    }

    if (x==-1){
        cout<<"NO\n";
        return 0;
    }

    for (int i=1;i<=n;i++){
        x=pre[x];
    }

    vector<int> ans;
    int cur=x;

    while (1){
        ans.push_back(cur);
        cur=pre[cur];

        if (cur==x){
            ans.push_back(cur);
            break;
        }
    }
    reverse(ans.begin(),ans.end());
    
    cout<<"YES\n";
    for (int v:ans){
        cout<<v<<' ';
    }
    cout<<'\n';

    return 0;
}