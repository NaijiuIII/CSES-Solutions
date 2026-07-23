#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    vector<int> q(t);
    int mx;
    for (int i=0;i<t;i++){
        cin>>q[i];
        mx=max(mx,q[i]);
    }

    int limit=sqrt(mx);
    int base=limit+1;

    vector<int> v(mx+1,-1);

    for (int a=0;a<=limit;a++){
        for (int b=0;b<=a;b++){
            int x=a*a+b*b;

            if (x>mx) break;

            if (v[x]==-1){
                v[x]=a*base+b;
            }
        }
    }

    for (int n:q){
        for (int x=0;x<=n/2;x++){
            if (v[x]==-1) continue;
            if (v[n-x]==-1) continue;

            int p1=v[x];
            int p2=v[n-x];

            int a=p1/base;
            int b=p1%base;
            int c=p2/base;
            int d=p2%base;

            cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
            break;
        }
    }
    return 0;
}