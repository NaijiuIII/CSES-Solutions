#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<vector<int>> g(n+1);
    vector<char> vis(n+1,false);
    vector<int> pre(n+1,-1);

    int m;
    cin>>m;
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    vis[1]=true;

    while (!q.empty()){
        auto cur=q.front();
        q.pop();

        for (int x:g[cur]){
            if (!vis[x]){
                vis[x]=true;
                pre[x]=cur;
                q.push(x);
            }
        }
    }

    if (pre[n]==-1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

    vector<int> road;
    road.push_back(n);
    int temp=pre[n];

    while (temp!=-1){
        road.push_back(temp);
        temp=pre[temp];
    }

    cout<<road.size()<<'\n';
    for (int i=road.size()-1;i>=0;i--){
        if (i!=road.size()-1) cout<<' ';
        cout<<road[i];
    }
    cout<<'\n';
    return 0;
}