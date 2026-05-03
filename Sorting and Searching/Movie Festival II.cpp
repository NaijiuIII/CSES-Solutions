#include <bits/stdc++.h>
using namespace std;
 


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    vector<pair<int,int>> a(n);
    for (int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }

    sort(a.begin(),a.end(),[](auto &x,auto &y){
        return x.second<y.second;
    });

    multiset<int> s;
    for (int i=0;i<k;i++) s.insert(0);

    int ans=0;
    for (auto &cur:a){
        auto pos=s.upper_bound(cur.first);
        if (pos!=s.begin()){
            pos--;
            s.erase(pos);
            s.insert(cur.second);
            ans++;
        }
    }  

    cout<<ans<<'\n';
    return 0; 
}