#include <bits/stdc++.h>
using namespace std;

int n,q;
vector<vector<int>> bit;
vector<string> g;

void add(int y,int x,int v){
    for (int i=y;i<=n;i+=i&(-i)){
        for (int j=x;j<=n;j+=j&(-j)){
            bit[i][j]+=v;
        }
    }
}

int sum(int y,int x){
    int res=0;
    for (int i=y;i>0;i-=i&(-i)){
        for (int j=x;j>0;j-=j&(-j)){
            res+=bit[i][j];
        }
    }

    return res;
}

int query(int y1,int x1,int y2,int x2){
    return sum(y2,x2)
        -sum(y1-1,x2)
        -sum(y2,x1-1)
        +sum(y1-1,x1-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;
    bit.assign(n+1,vector<int>(n+1,0));
    g.assign(n+1,"");

    for (int i=1;i<=n;i++){
        string s;
        cin>>s;
        g[i]=" "+s;

        for (int j=1;j<=n;j++){
            if (g[i][j]=='*'){
                add(i,j,1);
            }
        }
    }

    while (q--){
        int op;
        cin>>op;

        if (op==1){
            int y,x;
            cin>>y>>x;
            if (g[y][x]=='.'){
                g[y][x]='*';
                add(y,x,+1);
            }
            else{
                g[y][x]='.';
                add(y,x,-1);
            }
        }
        else{
            int y1,x1,y2,x2;
            cin>>y1>>x1>>y2>>x2;

            cout<<query(y1,x1,y2,x2)<<'\n';
        }
    }
    return 0;
}