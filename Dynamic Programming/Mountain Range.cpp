#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> h;
vector<int> L;
vector<int> R;
vector<int> dp;

vector<int> seg;

void update(int id,int l,int r,int pos,int val){
    if (l==r){
        seg[id]=val;
        return;
    }

    int mid=(l+r)/2;

    if (pos<=mid){
        update(id*2,l,mid,pos,val);
    }
    else update(id*2+1,mid+1,r,pos,val);

    seg[id]=max(seg[id*2],seg[2*id+1]);
}

int query(int id,int l,int r,int ql,int qr){
    if (ql>qr) return 0;

    if (ql<=l&&r<=qr){
        return seg[id];
    }

    int mid=(l+r)/2;
    int res=0;

    if (ql<=mid) res=max(res,query(id*2,l,mid,ql,qr));
    if (qr>mid) res=max(res,query(id*2+1,mid+1,r,ql,qr));

    return res;
}   

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    h.resize(n+1);
    L.resize(n+1);
    R.resize(n+1);
    dp.resize(n+1);
    seg.resize(4*n+1);

    for (int i=1;i<=n;i++){
        cin>>h[i];
    }

    stack<int> st;

    for (int i=1;i<=n;i++){
        while (!st.empty()&&h[st.top()]<h[i]) st.pop();

        if (st.empty()) L[i]=0;
        else L[i]=st.top();

        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i=n;i>=1;i--){
        while (!st.empty()&&h[st.top()]<h[i]) st.pop();

        if (st.empty()) R[i]=n+1;
        else R[i]=st.top();

        st.push(i);
    }

    vector<int> id(n);

    for (int i=0;i<n;i++) id[i]=i+1;

    sort(id.begin(),id.end(),[&](int a,int b){
        return h[a]<h[b];
    });

    int ans=1;

    for (int i=0;i<n;){
        int j=i;
        while (j<n&&h[id[j]]==h[id[i]]) j++;

        for (int k=i;k<j;k++){
            int pos=id[k];

            int l=L[pos]+1;
            int r=R[pos]-1;

            int best=query(1,1,n,l,r);
            dp[pos]=best+1;

            ans=max(ans,dp[pos]);
        }

        for (int k=i;k<j;k++){
            int pos=id[k];

            update(1,1,n,pos,dp[pos]);
        }

        i=j;
    }

    cout<<ans<<'\n';
    return 0;
}
