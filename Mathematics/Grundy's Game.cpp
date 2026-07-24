#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    const int N=2000;

    vector<int> sg(N+1);
    vector<int> vis(N+1);

    for (int n=3;n<=N;n++){
        for (int i=1;i*2<n;i++){
            int x=sg[i]^sg[n-i];

            if (x<=N) vis[x]=n;
        }
        int mex=0;

        while (vis[mex]==n) mex++;

        sg[n]=mex;
    }

    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;

        if (n>N||sg[n]!=0) cout<<"first\n";
        else cout<<"second\n";
    }

    return 0;
}