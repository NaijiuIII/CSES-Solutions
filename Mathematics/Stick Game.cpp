#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;
    vector<int> p(k);
    for (int i=0;i<k;i++){
        cin>>p[i];
    }
    sort(p.begin(),p.end());

    vector<char> dp(n+1,false);
    for (int i=1;i<=n;i++){
        for (int x:p){
            if (x>i) break;

            if (dp[i-x]==false){
                dp[i]=true;
                break;
            }
        }
    }

    for (int i=1;i<=n;i++){
        if (dp[i]){
            cout<<'W';
        }
        else cout<<'L';
    }
    cout<<'\n';
    return 0;
}