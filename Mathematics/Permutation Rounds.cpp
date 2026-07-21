#include <bits/stdc++.h>
using namespace std;

const int N=2e5+1;
const long long mod=1e9+7;

int n;
int p[N];
bool vis[N];
int spf[N];
int mx[N];

long long qpow(long long a,int b){
    long long ans=1;

    while (b>0){
        if (b&1) {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b>>=1;
    }

    return ans;
}

void Spf(){
    for (int i=2;i<N;i++){
        if (spf[i]==0){
            for (int j=i;j<=n;j+=i){
                if (spf[j]==0) spf[j]=i;
            }
        }
    }
}

void divide(int len){
    while (len>1){
        int x=spf[len];
        int cnt=0;

        while (len%x==0){
            len/=x;
            cnt++;
        }

        mx[x]=max(mx[x],cnt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>p[i];
    }

    Spf();

    for (int i=1;i<=n;i++){
        if (vis[i]) continue;

        int u=i;
        int len=0;

        while (!vis[u]){
            vis[u]=true;
            len++;
            u=p[u];
        }

        divide(len);
    }

    long long ans=1;
    for (int i=2;i<=n;i++){
        if (mx[i]){
            ans=ans*qpow(i,mx[i])%mod;
        }
    }

    cout<<ans<<'\n';
    return 0;
}