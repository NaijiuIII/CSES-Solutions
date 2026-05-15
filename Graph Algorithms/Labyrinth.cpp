#include <bits/stdc++.h>
using namespace std;

int n,m;
int sx,sy,tx,ty;
vector<vector<char>> g;
vector<int> dx={-1,1,0,0};
vector<int> dy={0,0,-1,1};
vector<char> dir={'U','D','L','R'};
vector<vector<char>> vis,pre;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    g.assign(n,vector<char>(m,'a'));
    vis.assign(n,vector<char>(m,false));
    pre.assign(n,vector<char>(m,0));

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>g[i][j];
            if (g[i][j]=='A') sx=i,sy=j;
            if (g[i][j]=='B') tx=i,ty=j;
        }
    }

    queue<pair<int,int>> q;
    q.push({sx,sy});
    vis[sx][sy]=true;

    while (!q.empty()){
        auto [x,y]=q.front();
        q.pop();

        for (int d=0;d<4;d++){
            int nx=x+dx[d];
            int ny=y+dy[d];

            if (nx<0||ny<0||nx>=n||ny>=m) continue;
            if (vis[nx][ny]||g[nx][ny]=='#') continue;

            vis[nx][ny]=true;
            pre[nx][ny]=dir[d];
            q.push({nx,ny});
        }
    }

    if (!vis[tx][ty]){
        cout<<"NO\n";
        return 0;
    }

    string ans;

    while(tx!=sx||ty!=sy){
        char c=pre[tx][ty];
        ans.push_back(c);

        if (c=='U') tx++;
        if (c=='D') tx--;
        if (c=='L') ty++;
        if (c=='R') ty--;
    }

    reverse(ans.begin(),ans.end());

    cout<<"YES\n";
    cout<<ans.size()<<'\n';
    cout<<ans<<'\n';
    return 0;
}