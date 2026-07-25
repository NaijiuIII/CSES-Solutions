#include <bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;
const int N=1e6+1;

int tr[N][26];
bool ed[N];
int tot=0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;

    int k;
    cin>>k;

    for (int i=0;i<k;i++){
        string t;
        cin>>t;

        int u=0;

        for (char ch:t){
            int c=ch-'a';

            if (tr[u][c]==0) tr[u][c]=++tot;
            u=tr[u][c];
        }
        ed[u]=true;
    }

    int n=s.size();
    vector<int> dp(n+1,0);
    dp[0]=1;

    for (int i=0;i<n;i++){
        if (dp[i]==0) continue;
        int u=0;

        for (int j=i;j<n;j++){
            int c=s[j]-'a';

            if (tr[u][c]==0) break;
            u=tr[u][c];

            if (ed[u]){
                dp[j+1]+=dp[i];
                if (dp[j+1]>=mod) dp[j+1]-=mod;
            }
        }
    }

    cout<<dp[n]<<'\n';
    return 0;
}