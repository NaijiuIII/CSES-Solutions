#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
	cin>>n;
	
	vector<int> to(n+1);
	vector<vector<int>> rev(n+1);
	vector<int> deg(n+1,0);
	vector<int> incycle(n+1,1);

	for (int i=1;i<=n;i++){
		cin>>to[i];
		deg[to[i]]++;
		rev[to[i]].push_back(i);
	}

	queue<int> q;
	for (int i=1;i<=n;i++){
		if (deg[i]==0) q.push(i);
	}

	while (!q.empty()){
		int u=q.front();
		q.pop();

		incycle[u]=0;

		int v=to[u];
		deg[v]--;
		if (deg[v]==0) q.push(v);
	}

	vector<int> ans(n+1,0);

	for (int i=1;i<=n;i++){
		if (incycle[i]&&ans[i]==0){
			vector<int> cyc;
			int u=i;

			while (ans[u]==0){
				cyc.push_back(u);
				ans[u]=-1;
				u=to[u];
			}

			for (int x:cyc){
				ans[x]=cyc.size();
			}
		}
	}

	queue<int> bfs;
	for (int i=1;i<=n;i++){
		if (incycle[i]) bfs.push(i);
	}

	while (!bfs.empty()){
		int u=bfs.front();
		bfs.pop();

		for (int v:rev[u]){
			if (incycle[v]) continue;
			if (ans[v]!=0) continue;

			ans[v]=ans[u]+1;
			bfs.push(v);
		}
	}

	for (int i=1;i<=n;i++){
		if (i!=1) cout<<' ';
		cout<<ans[i];
	}
	cout<<'\n';
    return 0;
}