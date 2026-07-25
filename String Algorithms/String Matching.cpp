#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s,p;
    cin>>s>>p;

    int n=s.size();
    int m=p.size();

    vector<int> nxt(m,0);

    for (int i=1,j=0;i<m;i++){
        while (j>0&&p[i]!=p[j]){
            j=nxt[j-1];
        }
        if (p[i]==p[j]){
            j++;
        }
        nxt[i]=j;
    }

    int ans=0;

    for (int i=0,j=0;i<n;i++){
        while (j>0&&s[i]!=p[j]){
            j=nxt[j-1];
        }
        if (s[i]==p[j]){
            j++;
        }
        if (j==m){
            ans++;
            j=nxt[j-1];
        }
    }

    cout<<ans<<'\n';

    return 0;
}