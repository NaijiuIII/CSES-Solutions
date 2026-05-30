#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	int n,m;
	cin>>n>>m;
	vector<vector<int>> g(n+1);
	vector<vector<int>> rg(n+1);
	
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		rg[b].push_back(a);
	}

	auto bfs=[&](vector<vector<int>> &g){
		vector<char> vis(n+1,false);
		queue<int> q;

		vis[1]=true;
		q.push(1);

		while (!q.empty()){
			int u=q.front();
			q.pop();

			for (int v:g[u]){
				if (vis[v]) continue;
				vis[v]=true;
				q.push(v);
			}
		}

		return vis;
	};

	vector<char> vis=bfs(g);
	for (int i=1;i<=n;i++){
		if (!vis[i]){
			cout<<"NO\n";
			cout<<1<<' '<<i<<'\n';
			return 0;
		}
	}

	vis=bfs(rg);

	for (int i=1;i<=n;i++){
		if (!vis[i]){
			cout<<"NO\n";
			cout<<i<<' '<<1<<'\n';
			return 0;
		}
	}

	cout<<"YES\n";
    return 0;
}