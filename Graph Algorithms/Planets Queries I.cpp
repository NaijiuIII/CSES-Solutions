#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
	cin>>n>>q;
	vector<int> t(n+1,0);
	for (int i=1;i<=n;i++){
		cin>>t[i];
	}

	vector<vector<int>> up(n+1,vector<int>(31,0));
	for (int i=1;i<=n;i++) up[i][0]=t[i];

	for (int j=1;j<31;j++){
		for (int i=1;i<=n;i++){
			up[i][j]=up[up[i][j-1]][j-1];
		}
	}

	while (q--){
		int x,k;
		cin>>x>>k;

		for (int i=0;i<31;i++){
			if ((k>>i)&1==1){
				x=up[x][i];
			}
		}

		cout<<x<<'\n';
	}
    return 0;
}