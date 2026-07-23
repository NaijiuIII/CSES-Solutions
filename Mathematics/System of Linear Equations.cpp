#include <bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    vector<vector<long long>> a(n,vector<long long>(m+1));

    for (int i=0;i<n;i++){
        for (int j=0;j<=m;j++){
            cin>>a[i][j];
        }
    }

    auto qpow=[&](long long x,long long y){
        long long ans=1;

        while (y>0){
            if (y&1){
                ans=ans*x%mod;
            }

            x=x*x%mod;
            y>>=1;
        }

        return ans;
    };

    vector<int> where(m,-1);
    int row=0;

    for (int col=0;col<m&&row<n;col++){
        int sel=-1;

        for (int i=row;i<n;i++){
            if (a[i][col]!=0){
                sel=i;
                break;
            }
        }

        if (sel==-1) continue;

        swap(a[row],a[sel]);
        where[col]=row;

        long long inv=qpow(a[row][col],mod-2);
        for (int j=col;j<=m;j++){
            a[row][j]=a[row][j]*inv%mod;
        }

        for (int i=row+1;i<n;i++){
            if (a[i][col]==0) continue;

            long long factor=a[i][col];
            for (int j=col;j<=m;j++){
                a[i][j]=(a[i][j]-factor*a[row][j]%mod+mod)%mod;
            }
        }

        row++;
    }

    for (int i=0;i<n;i++){
        bool all0=true;

        for (int j=0;j<m;j++){
            if (a[i][j]!=0){
                all0=false;
                break;
            }
        }

        if (all0&&a[i][m]!=0){
            cout<<-1<<'\n';
            return 0;
        }
    }

    vector<long long> ans(m,0);
    for (int col=m-1;col>=0;col--){
        if (where[col]==-1) continue;
        int r=where[col];
        long long val=a[r][m];

        for (int j=col+1;j<m;j++){
            val=(val-a[r][j]*ans[j]%mod+mod)%mod;
        }

        ans[col]=val;
    }

    for (int i=0;i<m;i++){
        if (i) cout<<' ';
        cout<<ans[i];
    }
    cout<<'\n';
    return 0;
}