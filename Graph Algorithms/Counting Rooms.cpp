#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<string> g;
vector<int> dx={-1,1,0,0};
vector<int> dy={0,0,-1,1};
vector<vector<char>> vis;

void dfs(int x,int y){
    vis[x][y]=true;

    for (int d=0;d<4;d++){
        int nx=x+dx[d];
        int ny=y+dy[d];

        if (nx<0||ny<0||nx>=n||ny>=m) continue;
        if (vis[nx][ny]||g[nx][ny]=='#') continue;

        dfs(nx,ny);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    g.resize(n);
    vis.assign(n,vector<char>(m,false));

    for (int i=0;i<n;i++) cin>>g[i];

    int ans=0;

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (vis[i][j]||g[i][j]=='#') continue;
            
            ans++;
            dfs(i,j);
        }
    }

    cout<<ans<<'\n';
    return 0;
}