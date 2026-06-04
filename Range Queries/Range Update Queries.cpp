#include <bits/stdc++.h>
using namespace std;

int n,q;
vector<long long> a;
vector<long long> tree;

int lowbit(int x){
    return x&(-x);
}

void add(int pos,long long val){
    while (pos<=n){
        tree[pos]+=val;
        pos+=lowbit(pos);
    }
}

long long sum(int pos){
    long long ans=0;
    while (pos>0){
        ans+=tree[pos];
        pos-=lowbit(pos);
    }
    return ans;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;
    a.assign(n+1,0);
    tree.assign(n+2,0);

    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    while (q--){
        int op;
        cin>>op;
        if (op==1){
            int l,r;
            long long u;
            cin>>l>>r>>u;

            add(l,u);
            if (r+1<=n) add(r+1,-u);
        }
        else{
            int k;
            cin>>k;

            cout<<a[k]+sum(k)<<'\n';
        }
    }
    return 0;
}