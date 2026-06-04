#include <bits/stdc++.h>
using namespace std;

int n,q;
vector<long long> tree;
vector<long long> a;

int lowbit(int x){
    return x&(-x);
}

void add(long long val,int pos){
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

long long qsum(int l,int r){
    return sum(r)-sum(l-1);
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;
    a.assign(n+1,0);
    tree.assign(n+2,0);

    for (int i=1;i<=n;i++){
        cin>>a[i];
        add(a[i],i);
    }

    while (q--){
        int op;
        cin>>op;
        if (op==1){
            int k;
            long long u;
            cin>>k>>u;

            add(-a[k],k);
            a[k]=u;
            add(a[k],k);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<qsum(l,r)<<'\n';
        }
    }
    return 0;
}