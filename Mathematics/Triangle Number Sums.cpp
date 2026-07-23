#include <bits/stdc++.h>
using namespace std;

bool square(long long x){
    long long r=sqrtl(x);

    while ((r+1)*(r+1)<=x) r++;
    while (r*r>x) r--;

    return r*r==x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    vector<long long> q(t);
    long long mx=0;

    for (int i=0;i<t;i++){
        cin>>q[i];
        mx=max(mx,q[i]);
    }

    long long v=8*mx+2;
    int lim=sqrtl(v)+1;

    vector<char> vis(lim+1);
    vector<int> p;

    for (int i=2;i<=lim;i++){
        if (!vis[i]){
            p.push_back(i);

            if (1LL*i*i<=lim){
                for (long long j=1LL*i*i;j<=lim;j+=i){
                    vis[j]=true;
                }
            }
        }
    }

    for (long long n:q){
        if (square(8*n+1)){
            cout<<1<<'\n';
            continue;
        }

        long long x=8*n+2;
        bool ok=true;

        for (int y:p){
            if (1LL*y*y>x) break;

            if (x%y==0){
                int c=0;

                while (x%y==0){
                    x/=y;
                    c++;
                }

                if (y%4==3&&c%2==1){
                    ok=false;
                    break;
                }
            }
        }

        if (ok&&x%4==3) ok=false;

        if (ok) cout<<2<<'\n';
        else cout<<3<<'\n';
    }
    return 0;
}