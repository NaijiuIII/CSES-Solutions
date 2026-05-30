#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g,rg;
vector<int> vis,comp,order;

void dfs1(int u){
	vis[u]=1;

	for (int v:g[u]){
		if (!vis[v]) dfs1(v);
	}

	order.push_back(u);
}

void dfs2(int u,int c){
	comp[u]=c;

	for (int v:rg[u]){
		if (!comp[v]) dfs2(v,c);
	}
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin>>n>>m;
	g.resize(n+1);
	rg.resize(n+1);
	vis.assign(n+1,0);
	comp.assign(n+1,0);

	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;

		g[a].push_back(b);
		rg[b].push_back(a);
	}

	for (int i=1;i<=n;i++){
		if (!vis[i]) dfs1(i);
	}

	reverse(order.begin(),order.end());

	int cnt=0;

	for (int u:order){
		if (!comp[u]){
			cnt++;
			dfs2(u,cnt);
		}
	}

	cout<<cnt<<'\n';
	for (int i=1;i<=n;i++){
		cout<<comp[i]<<' ';
	}
    return 0;
}