#include <bits/stdc++.h>
using namespace std;

int ans[9][9];

int dx[8]={-2,-1,1,2,2,1,-1,-2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};

bool ok(int x,int y){
    return x>=1&&x<=8&&y>=1&&y<=8&&ans[x][y]==0;
}

int num(int x,int y){
    int cnt=0;

    for (int i=0;i<8;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if (ok(nx,ny)) cnt++;
    }

    return cnt;
}

struct node{
    int x,y;
    int num;

    bool operator<(const auto&other) const{
        return num<other.num;
    }
};

bool dfs(int x,int y,int step){
    if (step==65) return true;

    vector<node> nxt;

    for (int i=0;i<8;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if (ok(nx,ny)) nxt.push_back({nx,ny,num(nx,ny)});
    }

    sort(nxt.begin(),nxt.end());

    for (auto [nx,ny,d]:nxt){
        ans[nx][ny]=step;

        if (dfs(nx,ny,step+1)) return true;

        ans[nx][ny]=0;

    }

    return false;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x,y;
    cin>>y>>x;
    ans[x][y]=1;

    if (dfs(x,y,2)){
        for (int i=1;i<9;i++){
            for (int j=1;j<9;j++){
                if (j!=1) cout<<' ';
                cout<<ans[i][j];
            }
            cout<<'\n';
        }
    }
    return 0;
}