#include <bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;

struct M{
    long long a[2][2]={};
};

M mul(M x,M y){
    M z;

    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            for (int k=0;k<2;k++){
                z.a[i][j]=(z.a[i][j]+
                        x.a[i][k]*y.a[k][j])%mod;
            }
        }
    }

    return z;
}

M qpow(M a,long long b){
    M ans;

    ans.a[0][0]=1;
    ans.a[1][1]=1;

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

    if (n==0||n==1){
        cout<<n<<'\n';
        return 0;
    }    

    M b;
    b.a[0][0]=1;
    b.a[0][1]=1;
    b.a[1][0]=1;
    b.a[1][1]=0;

    M ans=qpow(b,n);
    cout<<ans.a[0][1]<<'\n';
    return 0;
}