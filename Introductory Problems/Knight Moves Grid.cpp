#include <bits/stdc++.h>
using namespace std;

 
int n;
vector<vector<int>> step;
vector<int> dx={-2,-1,1,2,2,1,-1,-2};
vector<int> dy={1,2,2,1,-1,-2,-2,-1};
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin>>n;
    step.assign(n,vector<int>(n,1e9));
    step[0][0]=0;
     
    queue<pair<int,int>> q;
    q.push({0,0});
 
    while (!q.empty()){
        auto cur=q.front();
        q.pop();
 
        for (int i=0;i<8;i++){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
 
            if (nx<0||ny<0||nx>=n||ny>=n) continue;
            int nstep=step[cur.first][cur.second]+1;
            if (nstep<step[nx][ny]){
                q.push({nx,ny});
                step[nx][ny]=nstep;
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (j) cout<<' ';
            cout<<step[i][j];
        }
        cout<<endl;
    }
 
    return 0;
}