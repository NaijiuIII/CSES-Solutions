#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
	cin>>n>>m;

	const long long mod=1e9+7;

	vector<vector<long long>> g(n+1);
	vector<int> deg(n+1,0);
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		deg[b]++;
		g[a].push_back(b);
	}

	queue<int> q;

	for (int i=1;i<=n;i++){
		if (deg[i]==0) q.push(i);
	}

	vector<int> topo;

	while (!q.empty()){
		int u=q.front();
		q.pop();

		topo.push_back(u);
		for (int v:g[u]){
			deg[v]--;
			if (deg[v]==0) q.push(v);
		}
	}

	vector<long long> dp(n+1,0);
	dp[1]=1;
	for (int u:topo){
		if (dp[u]==0) continue;

		for (int v:g[u]){
			if (dp[v]==-1){
				dp[v]=dp[u]%mod;
			}
			else{
				dp[v]=(dp[v]+dp[u])%mod;
			}
		}
	}

	cout<<dp[n]<<'\n';
	
    return 0;
}