#include <bits/stdc++.h>
using namespace std;


vector<int> dx={-1,1,0,0};
vector<int> dy={0,0,-1,1};
vector<vector<char>> vis(7,vector<char>(7,false));
int res=0;
string s;

void dfs(int x,int y,int step){
    if (x==6&&y==0){
        if (step==48) res++;
        return;
    }

    if (step==48) return;

    bool up=(x==0||vis[x-1][y]);
    bool down=(x==6||vis[x+1][y]);
    bool left=(y==0||vis[x][y-1]);
    bool right=(y==6||vis[x][y+1]);

    if (up&&down&&!left&&!right) return;
    if (!up&&!down&&left&&right) return;

    vis[x][y]=true;

    if (s[step]=='?'){
        for (int d=0;d<4;d++){
            int nx=x+dx[d];
            int ny=y+dy[d];

            if (nx<0||ny<0||nx>6||ny>6) continue;
            if (vis[nx][ny]) continue;

            dfs(nx,ny,step+1);
        }
    }
    else{
        int d;
        if (s[step]=='U') d=0;
        else if (s[step]=='D') d=1;
        else if (s[step]=='L') d=2;
        else d=3;

        int nx=x+dx[d];
        int ny=y+dy[d];

        if (nx>=0&&ny>=0&&nx<=6&&ny<=6&&!vis[nx][ny]){
            dfs(nx,ny,step+1);
        }
    }

    vis[x][y]=false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin>>s;
    dfs(0,0,0);

    cout<<res<<'\n';
    return 0;
}