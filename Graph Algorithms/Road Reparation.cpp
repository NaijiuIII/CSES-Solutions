#include <bits/stdc++.h>
using namespace std;

int n,m;
struct edge{
	int a,b;
	long long c;

	bool operator<(const auto&other) const{
		return c<other.c;
	}
};

vector<edge> e;
vector<int> parent;

int find(int x){
	if (parent[x]!=x) parent[x]=find(parent[x]);
	return parent[x];
}

bool unite(int a,int b){
	a=find(a);
	b=find(b);

	if (a==b) return false;

	parent[a]=b;
	return true;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin>>n>>m;
	e.resize(m);
	parent.assign(n+1,0);
	for (int i=1;i<=n;i++){
		parent[i]=i;
	}

	for (int i=0;i<m;i++){
		int a,b;
		long long c;
		cin>>a>>b>>c;
		e[i]={a,b,c};
	}

	sort(e.begin(),e.end());

	long long ans=0;
	int cnt=0;

	for (auto x:e){
		if (unite(x.a,x.b)){
			cnt++;
			ans+=x.c;
		}
	}

	if (cnt==n-1) cout<<ans;
	else cout<<"IMPOSSIBLE";
	cout<<'\n';
    return 0;
}