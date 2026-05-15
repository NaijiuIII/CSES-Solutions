#include <bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;
vector<int> tr;

int lowbit(int x){
    return x&(-x);
}

void add(int idx,int val){
    while (idx<tr.size()){
        tr[idx]=(tr[idx]+val)%mod;
        idx+=lowbit(idx);
    } 
}

long long query(int idx){
    long long res=0;
    while (idx>0){
        res=(res+tr[idx])%mod;
        idx-=lowbit(idx);
    }

    return res;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> x(n);
    for (int i=0;i<n;i++) cin>>x[i];

    vector<int> b=x;
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());

    int m=b.size();
    tr.assign(m+1,0);

    int ans=0;

    for (int i=0;i<n;i++){
        int pos=lower_bound(b.begin(),b.end(),x[i])-b.begin()+1;

        int cur=(query(pos-1)+1)%mod;

        ans=(ans+cur)%mod;
        add(pos,cur);
    }

    cout<<ans<<'\n';
    return 0;
}