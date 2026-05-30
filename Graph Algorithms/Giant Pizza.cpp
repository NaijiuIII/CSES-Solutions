#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g,rg;
vector<int> vis,comp,order;

int getid(char c,int x){
	if (c=='+') return 2*x;
	return 2*x+1;
}

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
	g.resize(2*m+2);
	rg.resize(2*m+2);
	vis.assign(2*m+2,0);
	comp.assign(2*m+2,0);

	
	for (int i=1;i<=n;i++){
		char c1,c2;
		int x1,x2;

		cin>>c1>>x1>>c2>>x2;

		int a=getid(c1,x1);
		int b=getid(c2,x2);

		g[a^1].push_back(b);
		g[b^1].push_back(a);

		rg[a].push_back(b^1);
		rg[b].push_back(a^1);
	}

	for (int i=2;i<=2*m+1;i++){
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

	vector<char> ans(m+1);

	for (int i=1;i<=m;i++){
		int a=2*i;
		int b=2*i+1;

		if (comp[a]==comp[b]){
			cout<<"IMPOSSIBLE\n";
			return 0;
		}

		if (comp[a]>comp[b]) ans[i]='+';
		else ans[i]='-';
	}

	for (int i=1;i<=m;i++){
		if (i!=1) cout<<' ';
		cout<<ans[i];
	}
	cout<<'\n';
    return 0;
}