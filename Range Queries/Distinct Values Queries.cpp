#include <bits/stdc++.h>
using namespace std;

int n,q;
struct Query{
    int l,r,id;
};

vector<int> bit;

void add(int pos,int val){
    while (pos<=n){
        bit[pos]+=val;
        pos+=pos&(-pos);
    }
}

int sum(int pos){
    int res=0;
    while (pos>0){
        res+=bit[pos];
        pos-=pos&(-pos);
    }
    return res;
}

int query(int l,int r){
    return sum(r)-sum(l-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;
    vector<long long> a(n+1);
    for (int i=1;i<=n;i++) cin>>a[i];

    vector<Query> qs(q);

    for (int i=0;i<q;i++){
        cin>>qs[i].l>>qs[i].r;
        qs[i].id=i;
    }

    sort(qs.begin(),qs.end(),[](auto x,auto y){
        return x.r<y.r;
    });

    bit.assign(n+1,0);
    vector<int> ans(q);

    map<long long,int> lastsite;
    int cur=0;

    for (auto [l,r,id]:qs){
        while (cur<r){
            cur++;
            long long x=a[cur];

            if (lastsite.count(x)){
                add(lastsite[x],-1);
            }

            add(cur,1);
            lastsite[x]=cur;
        }

        ans[id]=query(l,r);
    }

    for (int i=0;i<q;i++){
        cout<<ans[i]<<'\n';
    } 
    return 0;
}