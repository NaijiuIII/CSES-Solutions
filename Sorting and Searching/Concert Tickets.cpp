#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    int n,m;
    cin>>n>>m;
    multiset<long long> h;
    for (int i=0;i<n;i++){
        long long p;
        cin>>p;
        h.insert(p);
    }
    for (int i=0;i<m;i++){
        int maxp;
        cin>>maxp;
 
        auto pos=h.upper_bound(maxp);
        if (pos==h.begin()){
            cout<<-1<<'\n';
        }
        else{
            pos--;
            cout<<*pos<<'\n';
            h.erase(pos);
        }
    }
 
     
    return 0;
}