#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> road;
vector<char> vis;
vector<int> reps;

void dfs(int cur){
    vis[cur]=true;

    for (int x:road[cur]){
        if (!vis[x]) dfs(x);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    road.resize(n);
    vis.assign(n,false);

    int m;
    cin>>m;
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;

        road[a].push_back(b);
        road[b].push_back(a);
    }

    for (int i=0;i<n;i++){
        if (!vis[i]){
            dfs(i);
            reps.push_back(i);
        }
    }

    cout<<reps.size()-1<<'\n';
    for (int i=1;i<reps.size();i++){
        cout<<reps[i-1]+1<<' '<<reps[i]+1<<'\n';
    }
    return 0;
}