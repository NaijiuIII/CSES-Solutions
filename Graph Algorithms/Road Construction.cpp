#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> siz;
int maxsiz=1;
int num;

int find(int x){
	if (parent[x]!=x) parent[x]=find(parent[x]);
	return parent[x];
}

void unite(int a,int b){
	a=find(a);
	b=find(b);

	if (a==b) return ;

    if (siz[a]>siz[b]) swap(a,b);

	parent[a]=b;
	num--;
	siz[b]+=siz[a];
	maxsiz=max(maxsiz,siz[b]);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	int n,m;
	cin>>n>>m;
	num=n;
	parent.assign(n+1,0);
	siz.assign(n+1,1);
	for (int i=1;i<=n;i++){
		parent[i]=i;
	}

	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		unite(a,b);

		cout<<num<<' '<<maxsiz<<'\n';
	}
    return 0;
}