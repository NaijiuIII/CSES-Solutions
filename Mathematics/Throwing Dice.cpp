#include <bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;

struct M{
    long long a[6][6]={};
};

M mul(M x,M y){
    M z;

    for (int i=0;i<6;i++){
        for (int j=0;j<6;j++){
            for (int k=0;k<6;k++){
                z.a[i][j]=(z.a[i][j]+
                        x.a[i][k]*y.a[k][j])%mod;
            }
        }
    }

    return z;
}

M qpow(M a,long long b){
    M ans;

    for (int i=0;i<6;i++){
        ans.a[i][i]=1;
    }

    while (b>0){
        if (b&1){
            ans=mul(ans,a);
        }
        a=mul(a,a);

        b>>=1;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin>>n;

    long long f[6]={1,1,2,4,8,16};
    if (n<=5) {
        cout<<f[n]<<'\n';
        return 0;
    }

    M b;
    for (int j=0;j<6;j++) b.a[0][j]=1;
    b.a[1][0]=1;
    b.a[2][1]=1;
    b.a[3][2]=1;
    b.a[4][3]=1;
    b.a[5][4]=1;

    M ans=qpow(b,n-5);
    long long start[6]={f[5],f[4],f[3],f[2],f[1],f[0]};

    long long res=0;
    for (int j=0;j<6;j++){
        res=(res+ans.a[0][j]*start[j])%mod;
    }

    cout<<res<<'\n';
    return 0;
}