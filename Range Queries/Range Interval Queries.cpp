#include <bits/stdc++.h>
using namespace std;

struct query{
    int a,b;
    int id;
    int op;
    long long t;
};

int n,q;
vector<int> bit;

void add(int pos,int val){
    while (pos<=n){
        bit[pos]+=val;
        pos+=pos&-pos;
    }
}

int sum(int pos){
    int res=0;
    while (pos>0){
        res+=bit[pos];
        pos-=pos&-pos;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;

    vector<pair<long long,int>> a(n);
    for (int i=1;i<=n;i++){
        long long x;
        cin>>x;
        a[i-1]={x,i};
    }

    sort(a.begin(),a.end());

    vector<query> qs;
    vector<int> ans(q,0);

    for (int i=0;i<q;i++){
        int l,r;
        long long c,d;
        cin>>l>>r>>c>>d;

        qs.push_back({l,r,i,1,d});
        qs.push_back({l,r,i,-1,c-1});
    }

    sort(qs.begin(),qs.end(),[](auto x,auto y){
        return x.t<y.t;
    });

    bit.assign(n+1,0);
    int p=0;

    for (auto e:qs){
        while (p<n&&a[p].first<=e.t){
            add(a[p].second,1);
            p++;
        }

        int cnt=sum(e.b)-sum(e.a-1);

        ans[e.id]+=e.op*cnt;
    }

    for (int i=0;i<q;i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}