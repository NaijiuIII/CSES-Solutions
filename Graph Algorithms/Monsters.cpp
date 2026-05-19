#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    vector<vector<char>> g(n,vector<char>(m,0));
    queue<pair<int,int>> mon; 
    vector<vector<int>> mon_first(n,vector<int>(m,1e9));
    int sx,sy;

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>g[i][j];
            if (g[i][j]=='A') sx=i,sy=j;
            if (g[i][j]=='M'){
                mon.push({i,j});
                mon_first[i][j]=0;
            }
        }
    }

    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    char dir[4]={'U','D','L','R'};

    while (!mon.empty()){
        auto [x,y]=mon.front();
        mon.pop();

        for (int d=0;d<4;d++){
            int nx=x+dx[d];
            int ny=y+dy[d];

            if (nx<0||ny<0||nx>=n||ny>=m) continue;
            if (g[nx][ny]=='#') continue;

            if (mon_first[nx][ny]<=mon_first[x][y]+1) continue;

            mon_first[nx][ny]=mon_first[x][y]+1;
            mon.push({nx,ny});
        }
    }

    queue<pair<int,int>> q;
    vector<vector<int>> dis(n,vector<int>(m,-1));

    vector<vector<pair<int,int>>> pre(n,vector<pair<int,int>>(m,{-1,-1}));
    vector<vector<char>> way(n,vector<char>(m));

    q.push({sx,sy});
    dis[sx][sy]=0;

    if (sx==0||sx==n-1||sy==0||sy==m-1){
        cout<<"YES"<<'\n';
        cout<<"0\n";
        return 0;
    }

    int tx=-1,ty=-1;

    while (!q.empty()){
        auto [x,y] =q.front();
        q.pop();

        for (int d=0;d<4;d++){
            int nx=x+dx[d];
            int ny=y+dy[d];

            if (nx<0||ny<0||nx>=n||ny>=m) continue;
            if (g[nx][ny]=='#') continue;
            if (dis[nx][ny]!=-1) continue;
            if (mon_first[nx][ny]<=dis[x][y]+1) continue;

            dis[nx][ny]=dis[x][y]+1;
            pre[nx][ny]={x,y};
            way[nx][ny]=dir[d];

            q.push({nx,ny});
        }

        if (x==0||y==0||x==n-1||y==m-1){
            tx=x,ty=y;
            break;
        }
    }

    if (tx==-1){
        cout<<"NO\n";
    }
    else{
        vector<char> ans;
        while (tx!=sx||ty!=sy){
            ans.push_back(way[tx][ty]);
            auto [x,y]=pre[tx][ty];
            tx=x,ty=y;
        }
        reverse(ans.begin(),ans.end());

        cout<<"YES\n";
        cout<<ans.size()<<'\n';
        for (int i=0;i<ans.size();i++){
            cout<<ans[i];
        }
        cout<<'\n';
    }
    return 0;
}