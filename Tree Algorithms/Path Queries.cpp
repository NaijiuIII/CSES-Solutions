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

void range_add(int l,int r,int val){
    add(l,val);
    add(r+1,-val);
}

long long sum(int pos){
    long long res=0;
    while (pos>0){
        res+=bit[pos];
        pos-=lowbit(pos);
    }
    return res;
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
        range_add(tin[i],tout[i],v[i]);
    }

    while (q--){
        int op;
        cin>>op;

        if (op==1){
            int s;
            long long x;
            cin>>s>>x;

            long long diff=x-v[s];

            range_add(tin[s],tout[s],diff);
            v[s]=x;
        }
        else{
            int s;
            cin>>s;

            cout<<sum(tin[s])<<'\n';
        }
    }
    return 0;
}