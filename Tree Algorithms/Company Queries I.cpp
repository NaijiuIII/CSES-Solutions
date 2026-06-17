#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;

    const int log=20;
    vector<vector<int>> up(log,vector<int>(n+1,0));

    for (int i=2;i<=n;i++){
        cin>>up[0][i];
    }

    for (int j=1;j<log;j++){
        for (int i=1;i<=n;i++){
            up[j][i]=up[j-1][up[j-1][i]];
        }
    }

    while (q--){
        int x,k;
        cin>>x>>k;

        for (int j=0;j<log;j++){
            if ((k>>j)&1){
                x=up[j][x];
            }
        }

        if (x==0) cout<<-1<<'\n';
        else cout<<x<<'\n';

    }
    return 0;
}