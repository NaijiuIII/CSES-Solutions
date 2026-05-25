#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
	cin>>n>>m;

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

	vector<int> dp(n+1,-1);
	vector<int> pre(n+1,-1);
	dp[1]=1;
	for (int u:topo){
		if (dp[u]==-1) continue;

		for (int v:g[u]){
			if (dp[u]+1>dp[v]){
				dp[v]=dp[u]+1;
				pre[v]=u;
			}
		}
	}

	if (dp[n]==-1){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}

	cout<<dp[n]<<'\n';
	vector<int> ans;
	int cur=n;
	while (cur!=1){
		ans.push_back(cur);
		cur=pre[cur];
	}
    ans.push_back(1);
	reverse(ans.begin(),ans.end());

	for (int i=0;i<ans.size();i++){
		if (i) cout<<' ';
		cout<<ans[i];
	}
	cout<<'\n';
    return 0;
}