#include <bits/stdc++.h>
using namespace std;
 


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<string> g(n);
    for (int i=0;i<n;i++) cin>>g[i];

    string ans="";
    ans+=g[0][0];

    queue<pair<int,int>> q;
    q.push({0,0});

    vector<vector<int>> vis(n,vector<int>(n,0));
    int flag=0;

    for (int step=1;step<=2*n-2;step++){
        char now='Z'+1;
        vector<pair<int,int>> nxt;
        int siz=q.size();

        while (siz--){
            auto [x,y]=q.front();
            q.pop();

            if (x+1<n){
                now=min(now,g[x+1][y]);
                nxt.push_back({x+1,y});
            }
            if (y+1<n){
                now=min(now,g[x][y+1]);
                nxt.push_back({x,y+1});
            }
        }
        flag++;

        for (auto [x,y]:nxt){
            if (g[x][y]==now&&vis[x][y]!=flag){
                vis[x][y]=flag;
                q.push({x,y});
            }
        }

        ans+=now;
    }

    cout<<ans<<'\n';
    return 0; 
}