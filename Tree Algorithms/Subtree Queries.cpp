#include <bits/stdc++.h>
using namespace std;

int n,q;
vector<vector<int>> g;
vector<long long> v;
vector<int> tin,tout;

int times=0;

vector<long long> bit;

int lowbit(int x){
    return x&(-x);
}

void add(int pos,long long val){
    while (pos<=n){
        bit[pos]+=val;
        pos+=lowbit(pos);
    }
}

long long sum(int pos){
    long long res=0;
    while (pos>0){
        res+=bit[pos];
        pos-=lowbit(pos);
    }
    return res;
}

long long query(int l,int r){
    return sum(r)-sum(l-1);
}

void dfs(int u,int fa){
    times++;
    tin[u]=times;

    for (int v:g[u]){
        if (v==fa) continue;
        dfs(v,u);
    }
    tout[u]=times;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;

    g.resize(n+1);
    v.resize(n+1);
    tin.resize(n+1);
    tout.resize(n+1);
    bit.assign(n+1,0);

    for (int i=1;i<=n;i++){
        cin>>v[i];
    }

    for (int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1,0);

    for (int i=1;i<=n;i++){
        add(tin[i],v[i]);
    }

    while (q--){
        int op;
        cin>>op;

        if (op==1){
            int s;
            long long x;
            cin>>s>>x;

            add(tin[s],-v[s]);
            v[s]=x;
            add(tin[s],v[s]);
        }
        else{
            int s;
            cin>>s;

            cout<<query(tin[s],tout[s])<<'\n';
        }
    }
    return 0;
}