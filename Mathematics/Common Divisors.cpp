#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> cnt(1e6+1,0);
    int mx=0;

    for (int i=0;i<n;i++){
        int x;
        cin>>x;

        cnt[x]++;
        mx=max(mx,x);
    }

    for (int d=mx;d>=1;d--){
        int num=0;

        for (int j=d;j<=mx;j+=d){
            num+=cnt[j];
        }

        if (num>=2){
            cout<<d<<'\n';
            break;
        }
    }
    return 0;
}