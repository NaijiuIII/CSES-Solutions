#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
	cin>>n>>q;
	
	vector<int> to(n+1);
	vector<vector<int>> rev(n+1);
	vector<int> deg(n+1,0);

	for (int i=1;i<=n;i++){
		cin>>to[i];
		deg[to[i]]++;
		rev[to[i]].push_back(i);
	}

	vector<vector<int>> up(n+1,vector<int>(31));

	for (int i=1;i<=n;i++){
		up[i][0]=to[i];
	}

	for (int j=1;j<31;j++){
		for (int i=1;i<=n;i++){
			up[i][j]=up[up[i][j-1]][j-1];
		}
	}

	auto jump=[&](int x,int k){
		for (int j=0;j<31;j++){
			if ((k>>j)&1){
				x=up[x][j];
			}
		}
		return x;
	};

	queue<int> que;
	vector<int> incycle(n+1,1);

	for (int i=1;i<=n;i++){
		if (deg[i]==0) que.push(i);
	}

	while (!que.empty()){
		int u=que.front();
		que.pop();

		incycle[u]=0;

		int v=to[u];
		deg[v]--;

		if (deg[v]==0){
			que.push(v);
		}
	}

	vector<int> root(n+1,0);
	vector<int> pos(n+1,0);
	vector<int> dep(n+1,0);
	vector<int> len(1);

	int cid=0;

	for (int i=1;i<=n;i++){
		if (incycle[i]&&root[i]==0){
			cid++;

			int u=i;
			int cnt=0;

			while (root[u]==0){
				root[u]=cid;
				pos[u]=cnt;
				dep[u]=0;
				cnt++;
				u=to[u];
			}

			len.push_back(cnt);
		}
	}

	queue<int> bfs;
	for (int i=1;i<=n;i++){
		if (incycle[i]){
			bfs.push(i);
		}
	}

	while (!bfs.empty()){
		int u=bfs.front();
		bfs.pop();

		for (int v:rev[u]){
			if (incycle[v]) continue;
			if (root[v]!=0) continue;

			root[v]=root[u];
			dep[v]=dep[u]+1;
			bfs.push(v);
		}
	}

	while (q--){
		int a,b;
		cin>>a>>b;

		if (root[a]!=root[b]){
			cout<<-1<<'\n';
			continue;
		}

		if (dep[b]>0){
			int d=dep[a]-dep[b];

			if (d<0){
				cout<<-1<<'\n';
				continue;
			}

			if (jump(a,d)==b){
				cout<<d<<'\n';
			}
			else cout<<-1<<'\n';
		}
		else{
			int c=jump(a,dep[a]);
			int id=root[a];
			int dis=(pos[b]-pos[c]+len[id])%len[id];

			cout<<dep[a]+dis<<'\n';
		}
	}
    return 0;
}