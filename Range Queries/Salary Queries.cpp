#include <bits/stdc++.h>
using namespace std;

int n,q;
vector<int> p;
vector<int> all,bit;

void add(int i,int x){
    while (i<bit.size()){
        bit[i]+=x;
        i+=(i&-i);
    }
}

int query(int i){
    int ans=0;
    while (i>0){
        ans+=bit[i];
        i-=(i&-i);
    }
    return ans;
}

int getid(int x){
    return lower_bound(all.begin(),all.end(),x)-all.begin()+1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;
    p.resize(n+1);
    vector<pair<char,pair<int,int>>> querys(q);

    for (int i=1;i<=n;i++){
        cin>>p[i];
        all.push_back(p[i]);
    }

    for (int i=0;i<q;i++){
        char op;
        cin>>op;
        if (op=='!'){
            int k,x;
            cin>>k>>x;
            querys[i]={op,{k,x}};
            all.push_back(x);
        }
        else{
            int a,b;
            cin>>a>>b;
            querys[i]={op,{a,b}};
            all.push_back(a);
            all.push_back(b);
        }
    }

    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    bit.assign(all.size()+1,0);

    for (int i=1;i<=n;i++){
        add(getid(p[i]),1);
    }

    for (auto [op,pr]:querys){
        if (op=='!'){
            int k=pr.first,x=pr.second;
            add(getid(p[k]),-1);
            p[k]=x;
            add(getid(p[k]),1);
        }
        else{
            int a=pr.first,b=pr.second;
            cout<<query(getid(b))-query(getid(a)-1)<<'\n';
        }
    }
    return 0;
}