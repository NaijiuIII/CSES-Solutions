#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
	cin>>n>>m;

	const long long mod=1e9+7;

	vector<vector<pair<int,long long>>> g(n+1);
	for (int i=0;i<m;i++){
		int a,b;
		long long c;
		cin>>a>>b>>c;
		g[a].push_back({b,c});
	}

	vector<long long> dist(n+1,1e18);
	vector<long long> cnt(n+1,0);
	vector<long long> mn(n+1,1e18),mx(n+1,-1);
	dist[1]=0,cnt[1]=1,mn[1]=0,mx[1]=0;

	priority_queue<pair<long long,int>,
	vector<pair<long long,int>>,greater<pair<long long,int>>> q;

	q.push({0,1});

	while (!q.empty()){
		auto [w,u]=q.top();
		q.pop();

		if (w!=dist[u]) continue;

		for (auto [v,c]:g[u]){
			long long nd=dist[u]+c;
			if (nd<dist[v]){
				dist[v]=nd;
				cnt[v]=cnt[u];
				mn[v]=mn[u]+1;
				mx[v]=mx[u]+1;

				q.push({dist[v],v});
			}
			else if (nd==dist[v]){
				cnt[v]=(cnt[v]+cnt[u])%mod;
				mn[v]=min(mn[v],mn[u]+1);
				mx[v]=max(mx[v],mx[u]+1);
			}
		}
	}
	
	cout<<dist[n]<<' '<<cnt[n]<<' ';
	cout<<mn[n]<<' '<<mx[n]<<'\n';
    return 0;
}