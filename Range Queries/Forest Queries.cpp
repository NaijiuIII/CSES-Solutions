#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;
    vector<vector<int>> g(n+1,vector<int>(n+1,0));
    char c;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>c;
            if (c=='*') g[i][j]=1;
        }
    }

    vector<vector<int>> pre(n+1,vector<int>(n+1,0));
    pre[1][1]=g[1][1];
    for (int i=2;i<=n;i++){
        pre[i][1]=pre[i-1][1]+g[i][1];
        pre[1][i]=pre[1][i-1]+g[1][i];
    }
    for (int i=2;i<=n;i++){
        for (int j=2;j<=n;j++){
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+g[i][j];
        }
    }

    while (q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;

        cout<<pre[x2][y2]-pre[x1-1][y2]-pre[x2][y1-1]+pre[x1-1][y1-1]<<'\n';
    }
    return 0;
}