#include <bits/stdc++.h>
using namespace std;
 
int n;
vector<int> bit;

int lowbit(int x){
    return x&-x;
}

void add(int idx,int delta){
    while (idx<=n){
        bit[idx]+=delta;
        idx+=lowbit(idx);
    }
}

int sum(int idx){
    int res=0;
    while (idx>0){
        res+=bit[idx];
        idx-=lowbit(idx);
    }
    return res;
}

int find(int k){
    int pos=0;
    int step=1;

    while (step<=n) step<<=1;
    step>>=1;

    for (;step;step>>=1){
        int next=pos+step;
        if (next<=n&&bit[next]<k){
            k-=bit[next];
            pos=next;
        }
    }

    return pos+1;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long k;
    cin>>n>>k;

    bit.assign(n+2,0);
    for (int i=1;i<=n;i++){
        add(i,1);
    }

    int m=n;
    int s=1;
    vector<int> ans;

    while (m>0){
        int t=((s-1+k)%m)+1;

        int pos=find(t);
        ans.push_back(pos);

        add(pos,-1);
        m--;

        if (m>0){
            s=((t-1)%m)+1;
        }
    }

    for (int i=0;i<ans.size();i++){
        if (i) cout<<' ';
        cout<<ans[i];
    }
    cout<<'\n';

    return 0;
}