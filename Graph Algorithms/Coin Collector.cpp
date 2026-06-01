#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g,rg;
vector<long long> coin;
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
	coin.resize(n+1);
	vis.assign(n+1,0);
	comp.assign(n+1,0);

	for (int i=1;i<=n;i++) cin>>coin[i];

	for (int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		rg[b].push_back(a);
	}

	for (int i=1;i<=n;i++){
		if (!vis[i]){
			dfs1(i);
		}
	}

	reverse(order.begin(),order.end());

	int cnt=0;

	for (int u:order){
		if (!comp[u]){
			cnt++;
			dfs2(u,cnt);
		}
	}

	vector<long long> sum(cnt+1);
	for (int i=1;i<=n;i++){
		sum[comp[i]]+=coin[i];
	}

	vector<vector<int>> dag(cnt+1);

	vector<int> deg(cnt+1,0);
	for (int u=1;u<=n;u++){
		for (int v:g[u]){
			int a=comp[u];
			int b=comp[v];

			if (a!=b){
				dag[a].push_back(b);
				deg[b]++;
			}
		}
	}

	vector<long long> dp(cnt+1,0);

	queue<int> q;

	for (int i=1;i<=cnt;i++){
		dp[i]=sum[i];

		if (deg[i]==0){
			q.push(i);
		}
	}

	long long ans=0;

	while (!q.empty()){
		int u=q.front();
		q.pop();

		ans=max(ans,dp[u]);

		for (int v:dag[u]){
			dp[v]=max(dp[v],dp[u]+sum[v]);
			deg[v]--;

			if (deg[v]==0) q.push(v);
		}
	}

	cout<<ans<<'\n';

    return 0;
}