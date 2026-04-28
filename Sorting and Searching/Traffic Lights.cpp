#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,n;
    cin>>x>>n;
 
    vector<int> p(n);
    for (int i=0;i<n;i++) cin>>p[i];
 
    set<int> light={0,x};
    multiset<int> leng;
    leng.insert(x);
 
    for (int i=0;i<n;i++){
        auto r = light.upper_bound(p[i]);
        auto l=r;
        --l;
        leng.erase(leng.find(*r-*l));
 
        light.insert(p[i]);
        leng.insert(*r-p[i]);
        leng.insert(p[i]-*l);
        if (i) cout<<' ';
        cout<<*(--leng.end());
    }
    cout<<'\n';
 
}