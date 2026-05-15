#include <bits/stdc++.h>
using namespace std;

string s;
long long num[20][11][2];
bool vis[20][11][2];

long long dfs(int pos,int last,bool tight,bool started){
    if (pos==s.size()){
        return 1;
    }

    if (!tight&&vis[pos][last][started]) return num[pos][last][started];

    long long res=0;

    int up=tight ? s[pos]-'0' : 9;

    for (int d=0;d<=up;d++){
        bool ntight=tight&&(d==up);

        if (!started&&d==0){
            res+=dfs(pos+1,10,ntight,false);
        }
        else{
            if (started&&d==last) continue;

            res+=dfs(pos+1,d,ntight,true);
        }
    }

    if (!tight){
        vis[pos][last][started]=true;
        num[pos][last][started]=res;
    }

    return res;
}

long long solve(long long x){
    if (x<0) return 0;

    s=to_string(x);

    memset(vis,0,sizeof(vis));

    return dfs(0,10,true,false);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a,b;
    cin>>a>>b;

    cout<<solve(b)-solve(a-1)<<'\n';
    return 0;
}